// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/WeatherHistory.h"

#include "Apixu/Response/Location.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"

namespace Apixu {
    namespace Response {
        const Location &WeatherHistory::getLocation() const {
            return location;
        }

        const Forecast::ForecastWeather &WeatherHistory::getForecast() const {
            return forecast;
        }
    }  // namespace Response
}  // namespace Apixu
