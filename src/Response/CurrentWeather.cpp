// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/CurrentWeather.h"

#include "Apixu/Response/Location.h"
#include "Apixu/Response/Current.h"

namespace Apixu {
    namespace Response {
        using nlohmann::json;

        const Location &CurrentWeather::getLocation() const {
            return location;
        }

        const Current &CurrentWeather::getCurrent() const {
            return current;
        }
    }  // namespace Response
}  // namespace Apixu
