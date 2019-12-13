#include "gtest/gtest.h"
#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include "HttpClientMock.cpp"


namespace {
    class ApixuForecastTest : public ::testing::Test {
    public:
        const string url = "http://localhost:5000/forecast.json";
        const char *apiKey = "apikey";
        const string q = "Paris";
        map<string, string> params;

    protected:
        void SetUp() override {
            params["key"] = apiKey;
            params["q"] = q;
            params["days"] = "1";
        }
    };

    TEST_F(ApixuForecastTest, success) {
        int status = 200;
        string body = R"(
           {
               "location":{
                  "name":"ABCDEFGHIJKLMNOPQRST",
                  "region":"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                  "country":"ABCDEFGHIJKLMNOPQRS",
                  "lat":934.25,
                  "lon":617.0,
                  "tz_id":"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                  "localtime_epoch":1574708193,
                  "localtime":"2019-11-25 18:56:33"
               },
               "current":{
                  "last_updated_epoch":1574708193,
                  "last_updated":"2019-11-25 18:56:33",
                  "temp_c":335.5,
                  "temp_f":327.0,
                  "is_day":400,
                  "condition":{
                     "text":"ABCDE",
                     "icon":"ABCDEFGHIJKLMNOPQRSTUVW",
                     "code":623
                  },
                  "wind_mph":159.5,
                  "wind_kph":-91.0,
                  "wind_degree":-6,
                  "wind_dir":"ABCDEFGHIJKLMNOPQRSTUVWXYZAB",
                  "pressure_mb":-68.25,
                  "pressure_in":2.5,
                  "precip_mm":785.0,
                  "precip_in":588.75,
                  "humidity":-11,
                  "cloud":509,
                  "feelslike_c":284.25,
                  "feelslike_f":413.25,
                  "vis_km":356.75,
                  "vis_miles":440.5,
                  "uv":-8.0
               },
               "forecast":{
                  "forecastday":[
                     {
                        "date":"ABCDEFGHI",
                        "date_epoch":1574708193,
                        "day":{
                           "maxtemp_c":570.75,
                           "maxtemp_f":920.0,
                           "mintemp_c":484.0,
                           "mintemp_f":544.0,
                           "avgtemp_c":518.25,
                           "avgtemp_f":645.5,
                           "maxwind_mph":244.25,
                           "maxwind_kph":497.0,
                           "totalprecip_mm":582.75,
                           "totalprecip_in":298.0,
                           "avgvis_km":377.0,
                           "avgvis_miles":576.25,
                           "avghumidity":406.5,
                           "condition":{
                              "text":"ABCDEFGHIJKLM",
                              "icon":"ABCDEFGHIJKLMNO",
                              "code":430
                           },
                           "uv":978.25
                        },
                        "astro":{
                           "sunrise":"ABCDEFGHIJKLMNOPQRSTUVWX",
                           "sunset":"ABCDEFGHIJKLMNOPQRST",
                           "moonrise":"ABCDEFGHIJKLMNOPQRSTUVWXYZAB",
                           "moonset":"ABCDEFG"
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

        auto mockHttpClient = HttpClientMock::GetHttpClient(url, params, status, body);

        auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
        auto forecast = apixu->Forecast(q, 1);

        EXPECT_EQ("ABCDEFGHIJKLMNOPQRST", forecast.getLocation().getName());

        delete apixu;
    }

    TEST_F(ApixuForecastTest, error) {
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
        auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);

        ASSERT_THROW(apixu->Forecast(q, 1), Apixu::Exception::ApiException);

        delete apixu;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}