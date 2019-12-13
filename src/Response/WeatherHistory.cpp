// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/WeatherHistory.h"

#include "Apixu/Response/Location.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"

namespace Apixu {
    namespace Response {
        using nlohmann::json;
        using Apixu::Response::Location;
        using Apixu::Response::Forecast::ForecastWeather;

        const Location &WeatherHistory::getLocation() const {
            return location;
        }

        const ForecastWeather &WeatherHistory::getForecast() const {
            return forecast;
        }
    }  // namespace Response
}  // namespace Apixu
