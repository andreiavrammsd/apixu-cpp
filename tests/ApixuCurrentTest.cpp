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

class ApixuCurrentTest : public ::testing::Test {
   public:
    const string url = "http://localhost:5000/current.json";
    const char *apiKey = "apikey";
    const string q = "Paris";
    map<string, string> params;

   protected:
    void SetUp() override
    {
        params["key"] = apiKey;
        params["q"] = q;
    }
};

TEST_F(ApixuCurrentTest, success)
{
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
                "is_day": 1,
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

    auto mockHttpClient = HttpClientMock::GetClient(url, params, status, body);

    auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
    auto current = apixu->Current(q);

    // Location
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRST", current.getLocation().getName());
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", current.getLocation().getRegion());
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRS", current.getLocation().getCountry());
    EXPECT_EQ(934.25, current.getLocation().getLat());
    EXPECT_EQ(617.0, current.getLocation().getLon());
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZ",
              *current.getLocation().getTimezone());
    EXPECT_EQ(1574708193, *current.getLocation().getLocaltimeEpoch());

    struct tm expected {
        0
    };
    expected.tm_year = 2019 - 1900;
    expected.tm_mon = 11 - 1;
    expected.tm_mday = 25;
    expected.tm_hour = 18;
    expected.tm_min = 56;
    auto actual = current.getLocation().getLocaltime();

    EXPECT_EQ(mktime(&expected), mktime(&actual));

    // Current
    EXPECT_EQ(1574708193, *current.getCurrent().getLastUpdatedEpoch());

    actual = current.getCurrent().getLastUpdated();
    EXPECT_EQ(mktime(&expected), mktime(&actual));

    EXPECT_EQ(335.5, *current.getCurrent().getTempC());
    EXPECT_EQ(327.0, *current.getCurrent().getTempF());
    EXPECT_EQ(true, *current.getCurrent().isDay());

    EXPECT_EQ("ABCDE", *current.getCurrent().getCondition().getText());
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVW",
              *current.getCurrent().getCondition().getIcon());
    EXPECT_EQ(623, *current.getCurrent().getCondition().getCode());

    EXPECT_EQ(159.5, *current.getCurrent().getWindMph());
    EXPECT_EQ(-91.0, *current.getCurrent().getWindKph());
    EXPECT_EQ(-6, *current.getCurrent().getWindDegree());
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZAB",
              *current.getCurrent().getWindDir());
    EXPECT_EQ(-68.25, *current.getCurrent().getPressureMb());
    EXPECT_EQ(2.5, *current.getCurrent().getPressureIn());
    EXPECT_EQ(785.0, *current.getCurrent().getPrecipMm());
    EXPECT_EQ(588.75, *current.getCurrent().getPrecipIn());
    EXPECT_EQ(-11, *current.getCurrent().getHumidity());
    EXPECT_EQ(509, *current.getCurrent().getCloud());
    EXPECT_EQ(284.25, *current.getCurrent().getFeelslikeC());
    EXPECT_EQ(413.25, *current.getCurrent().getFeelslikeF());
    EXPECT_EQ(356.75, *current.getCurrent().getVisKm());
    EXPECT_EQ(440.5, *current.getCurrent().getVisMiles());
    EXPECT_EQ(-8.0, *current.getCurrent().getUv());

    delete apixu;
}

TEST_F(ApixuCurrentTest, error)
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

    ASSERT_THROW(apixu->Current(q), Apixu::Exception::ApiException);

    delete apixu;
}
}  // namespace ApixuTest
