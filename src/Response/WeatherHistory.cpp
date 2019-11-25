#include "WeatherHistory.hpp"
#include "Location.hpp"
#include "Forecast/ForecastWeather.hpp"

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
    }
}
