#include "../src/Apixu.hpp"
#include "../src/Exception/ApixuException.cpp"
#include "HttpClientMock.cpp"
#include "gtest/gtest.h"


namespace {
    class ApixuCurrentTest : public ::testing::Test {
    };

    const string url = "http://localhost:5000/current.json";
    const char* apiKey = "apikey";
    map<string, string> params;

    TEST_F(ApixuCurrentTest, success) {
        const string q = "Paris";

        params["key"] = apiKey;
        params["q"] = q;

        int status = 200;
        string body = R"(
           {
              "location": {
                "name": "ABCDEFGHIJKLMNOPQRST",
                "region": "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "country": "ABCDEFGHIJKLMNOPQRS",
                "lat": 934.25,
                "lon": 617.0,
                "tz_id": "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "localtime_epoch": 1574708193,
                "localtime": "2019-11-25 18:56:33"
              },
              "current": {
                "last_updated_epoch": 1574708193,
                "last_updated": "2019-11-25 18:56:33",
                "temp_c": 335.5,
                "temp_f": 327.0,
                "is_day": 400,
                "condition": {
                  "text": "ABCDE",
                  "icon": "ABCDEFGHIJKLMNOPQRSTUVW",
                  "code": 623
                },
                "wind_mph": 159.5,
                "wind_kph": -91.0,
                "wind_degree": -6,
                "wind_dir": "ABCDEFGHIJKLMNOPQRSTUVWXYZAB",
                "pressure_mb": -68.25,
                "pressure_in": 2.5,
                "precip_mm": 785.0,
                "precip_in": 588.75,
                "humidity": -11,
                "cloud": 509,
                "feelslike_c": 284.25,
                "feelslike_f": 413.25,
                "vis_km": 356.75,
                "vis_miles": 440.5,
                "uv": -8.0
              }
            }
        )";

        auto mockHttpClient = HttpClientMock::GetHttpClient(url, params, status, body);

        auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
        auto current = apixu->Current(q);

        EXPECT_EQ("ABCDEFGHIJKLMNOPQRST", current.getLocation().getName());

        delete apixu;
    }

    TEST_F(ApixuCurrentTest, error) {
        int status = 400;
        string body = R"(
            {
                "error": {
                  "message":"err",
                  "code":1
               }
            }
        )";

        auto mockHttpClient = HttpClientMock::GetHttpClient(url, params, status, body);
        auto apixu = new Apixu::Apixu("", mockHttpClient);

        ASSERT_THROW(apixu->Conditions(), Apixu::Exception::ApixuException);

        delete apixu;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
