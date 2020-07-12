// Copyright 2020 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_H_

#include "Apixu/Response/Forecast/forecast_weather.h"
#include "Apixu/Response/current.h"
#include "Apixu/Response/location.h"
#include "nlohmann/json.hpp"

namespace apixu {
namespace response {
namespace forecast {
struct WeatherForecast {
    Location location;
    Current current;
    ForecastWeather forecast{};

    friend void from_json(const nlohmann::json& j, WeatherForecast& f);
};

inline void from_json(const nlohmann::json& j, WeatherForecast& f)
{
    f.location = j.at("location");
    f.current = j.at("current");
    f.forecast = j.at("forecast");
}
}  // namespace forecast
}  // namespace response
}  // namespace apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_H_
