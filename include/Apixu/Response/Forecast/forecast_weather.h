// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_

#include <vector>

#include "Apixu/Response/Forecast/forecast_day.h"
#include "nlohmann/json.hpp"

namespace apixu {
namespace response {
namespace forecast {
struct ForecastWeather {
    std::vector<ForecastDay> forecast_day;

    friend void from_json(const nlohmann::json &j,
                          ForecastWeather &f);  // NOLINT
};

inline void from_json(const nlohmann::json &j, ForecastWeather &f)
{  // NOLINT
    f.forecast_day = j.at("forecastday").get<std::vector<ForecastDay>>();
}
}  // namespace forecast
}  // namespace response
}  // namespace apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTWEATHER_H_
