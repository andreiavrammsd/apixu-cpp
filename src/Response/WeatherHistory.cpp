#include "Apixu/Response/WeatherHistory.hpp"
#include "Apixu/Response/Location.hpp"
#include "Apixu/Response/Forecast/ForecastWeather.hpp"

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
