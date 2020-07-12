// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_WEATHERFORECAST_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_WEATHERFORECAST_H_

#include "Apixu/Response/Current.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"
#include "Apixu/Response/Location.h"
#include "nlohmann/json.hpp"

namespace Apixu {
namespace Response {
namespace Forecast {
struct WeatherForecast {
    Location location;
    Current current;
    ForecastWeather forecast{};

    friend void from_json(const nlohmann::json &j,
                          WeatherForecast &f);  // NOLINT
};

inline void from_json(const nlohmann::json &j, WeatherForecast &f)
{  // NOLINT
    f.location = j.at("location");
    f.current = j.at("current");
    f.forecast = j.at("forecast");
}
}  // namespace Forecast
}  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_WEATHERFORECAST_H_
