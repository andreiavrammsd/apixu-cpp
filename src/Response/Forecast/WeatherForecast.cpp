#include "Apixu/Response/Forecast/WeatherForecast.hpp"
#include "Apixu/Response/Current.hpp"
#include "Apixu/Response/Forecast/ForecastWeather.hpp"

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
