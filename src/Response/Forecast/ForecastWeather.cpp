#ifndef APIXU_FORECAST_WEATHER_CPP
#define APIXU_FORECAST_WEATHER_CPP

#include "../../../include/nlohmann/json.hpp"
#include "ForecastDay.cpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::vector;

            class ForecastWeather {
            public:
                const vector<ForecastDay> &getForecastDay() const {
                    return forecastDay;
                }

            private:
                vector<ForecastDay> forecastDay;

                friend void from_json(const json &j, ForecastWeather &f);
            };

            inline void from_json(const json &j, ForecastWeather &f) {
                f.forecastDay = j.at("forecastday").get<vector<ForecastDay>>();
            }
        }
    }
}

#endif //APIXU_FORECAST_WEATHER_CPP
