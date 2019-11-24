#include "Forecast.hpp"
#include "../Current.hpp"
#include "ForecastWeather.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            const Location &Forecast::getLocation() const {
                return location;
            }

            const Current &Forecast::getCurrent() const {
                return current;
            }

            const ForecastWeather &Forecast::getForecast() const {
                return forecast;
            }
        }
    }
}
