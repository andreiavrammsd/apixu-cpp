// Copyright 2019 <Andrei Avram>
#include <map>
#include <string>

#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include "HttpClientMock.cpp"
#include "gtest/gtest.h"

namespace ApixuTest {
using std::map;
using std::string;

class ApixuHistoryTest : public ::testing::Test {
   public:
    const string url = "http://localhost:5000/history.json";
    const char *apiKey = "apikey";
    const string q = "Paris";
    map<string, string> params;

   protected:
    void SetUp() override
    {
        params["key"] = apiKey;
        params["q"] = q;
        params["dt"] = "2019-01-01";
    }
};

TEST_F(ApixuHistoryTest, success)
{
    int status = 200;
    string body = R"(
           {
              "location": {
                "name": "ABCDEFGHIJK",
                "region": "ABCDEFGHIJKLMNOP",
                "country": "ABCDEFGHIJKL",
                "lat": 504.0,
                "lon": 70.0,
                "tz_id": "ABCD",
                "localtime_epoch": -24,
                "localtime": "ABCDEFG"
              },
              "forecast": {
                "forecastday": [
                  {
                    "date": "ABCDEFGHIJKLMNOPQRSTUVWXYZABC",
                    "date_epoch": 319,
                    "day": {
                      "maxtemp_c": 66.5,
                      "maxtemp_f": 324.75,
                      "mintemp_c": 320.25,
                      "mintemp_f": 178.25,
                      "avgtemp_c": 50.5,
                      "avgtemp_f": -30.5,
                      "maxwind_mph": 29.0,
                      "maxwind_kph": 45.0,
                      "totalprecip_mm": 711.25,
                      "totalprecip_in": 300.0,
                      "avgvis_km": 84.25,
                      "avgvis_miles": 768.0,
                      "avghumidity": 775.0,
                      "condition": {
                        "text": "ABCDEFGHIJKLMNOPQRSTUVWX",
                        "icon": "ABCDEFG",
                        "code": 174
                      },
                      "uv": 128.5
                    },
                    "astro": {
                      "sunrise": "ABCDEFGHIJKLMNOPQRSTU",
                      "sunset": "ABCDEFGHIJKL",
                      "moonrise": "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                      "moonset": "ABCDEFGHIJKLMN",
                      "moon_phase": "ABCDEFGHIJKLMNOPQRSTU",
                      "moon_illumination": "ABCDEFGHIJKL"
                    },
                    "hour":[
                       {
                          "time_epoch":1574708193,
                          "time":"2019-11-25 18:56:33",
                          "temp_c":519.25,
                          "temp_f":282.75,
                          "is_day":147,
                          "condition":{
                             "text":"ABCDEFGHIJKLMNOPQRSTU",
                             "icon":"ABCDEFGHIJKLMN",
                             "code":861
                          },
                          "wind_mph":499.0,
                          "wind_kph":860.25,
                          "wind_degree":818,
                          "wind_dir":"ABCDEFGHIJKLMNOPQRSTUV",
                          "pressure_mb":360.75,
                          "pressure_in":793.5,
                          "precip_mm":373.5,
                          "precip_in":474.75,
                          "humidity":397,
                          "cloud":164,
                          "feelslike_c":922.25,
                          "feelslike_f":426.75,
                          "vis_km":861.0,
                          "vis_miles":723.0,
                          "gust_mph":688.0,
                          "gust_kph":286.75,
                          "uv":377.25
                       }
                    ]
                  }
                ]
              }
            }
        )";

    auto mockHttpClient = HttpClientMock::GetClient(url, params, status, body);

    auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
    auto history = apixu->History(q, "2019-01-01");

    EXPECT_EQ("ABCDEFGHIJK", history.getLocation().getName());

    delete apixu;
}

TEST_F(ApixuHistoryTest, error)
{
    int status = 400;
    string body = R"(
            {
                "error": {
                  "message":"err",
                  "code":1
               }
            }
        )";

    auto mockHttpClient = HttpClientMock::GetClient(url, params, status, body);
    auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);

    EXPECT_THROW(apixu->History(q, "2019-01-01"),
                 Apixu::Exception::ApiException);

    delete apixu;
}
}  // namespace ApixuTest
