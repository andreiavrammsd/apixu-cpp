// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_
#define INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_

#include "Apixu/Response/Forecast/forecast_weather.h"
#include "Apixu/Response/location.h"
#include "nlohmann/json.hpp"

namespace apixu {
namespace response {
struct WeatherHistory {
    Location location;
    forecast::ForecastWeather forecast;

    friend void from_json(const nlohmann::json &j,
                          WeatherHistory &h);  // NOLINT
};

inline void from_json(const nlohmann::json &j, WeatherHistory &h)
{  // NOLINT
    h.location = j.at("location");
    h.forecast = j.at("forecast");
}
}  // namespace response
}  // namespace apixu

#endif  // INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_
