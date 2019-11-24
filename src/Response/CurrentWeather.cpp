#include "CurrentWeather.hpp"
#include "Location.hpp"
#include "Current.hpp"

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
