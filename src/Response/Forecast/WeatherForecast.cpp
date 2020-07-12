// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Forecast/WeatherForecast.h"

#include "Apixu/Response/Current.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"

namespace Apixu {
namespace Response {
namespace Forecast {
const Location &WeatherForecast::getLocation() const { return location; }

const Current &WeatherForecast::getCurrent() const { return current; }

const ForecastWeather &WeatherForecast::getForecast() const { return forecast; }
}  // namespace Forecast
}  // namespace Response
}  // namespace Apixu
