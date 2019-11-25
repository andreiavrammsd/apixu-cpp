#include "WeatherForecast.hpp"
#include "../Current.hpp"
#include "ForecastWeather.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            const Location &WeatherForecast::getLocation() const {
                return location;
            }

            const Current &WeatherForecast::getCurrent() const {
                return current;
            }

            const ForecastWeather &WeatherForecast::getForecast() const {
                return forecast;
            }
        }
    }
}
