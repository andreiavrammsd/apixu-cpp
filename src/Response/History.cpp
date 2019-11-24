#include "History.hpp"
#include "Location.hpp"
#include "Forecast/ForecastWeather.hpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;
        using Apixu::Response::Location;
        using Apixu::Response::Forecast::ForecastWeather;

        const Location &History::getLocation() const {
            return location;
        }

        const ForecastWeather &History::getForecast() const {
            return forecast;
        }
    }
}
