#include "Apixu/Response/CurrentWeather.hpp"
#include "Apixu/Response/Location.hpp"
#include "Apixu/Response/Current.hpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;

        const Location &CurrentWeather::getLocation() const {
            return location;
        }

        const Current &CurrentWeather::getCurrent() const {
            return current;
        }
    }
}
