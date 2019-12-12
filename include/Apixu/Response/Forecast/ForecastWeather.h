#ifndef APIXU_RESPONSE_FORECAST_FORECAST_WEATHER_H_
#define APIXU_RESPONSE_FORECAST_FORECAST_WEATHER_H_

#include "Apixu/Response/Forecast/ForecastDay.h"
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::vector;

            class ForecastWeather {
            public:
                const vector<ForecastDay> &getForecastDay() const;

                virtual ~ForecastWeather() = default;

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

#endif // APIXU_RESPONSE_FORECAST_FORECAST_WEATHER_H_
