// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_

#include <vector>

#include "nlohmann/json.hpp"
#include "Apixu/Response/Forecast/ForecastDay.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            class ForecastWeather {
            public:
                const std::vector<ForecastDay> &getForecastDay() const;

                virtual ~ForecastWeather() = default;

            private:
                std::vector<ForecastDay> forecastDay;

                friend void from_json(const nlohmann::json &j, ForecastWeather &f); // NOLINT
            };

            inline void from_json(const nlohmann::json &j, ForecastWeather &f) { // NOLINT
                f.forecastDay = j.at("forecastday").get<std::vector<ForecastDay>>();
            }
        }  // namespace Forecast
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_
