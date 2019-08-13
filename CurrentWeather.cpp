#include "CurrentWeather.h"

namespace Apixu {
    const Location &CurrentWeather::getLocation() const {
        return location;
    }

    const Current &CurrentWeather::getCurrent() const {
        return current;
    }
}
