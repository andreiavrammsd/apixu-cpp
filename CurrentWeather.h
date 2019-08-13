#ifndef APIXU_DEV_CURRENT_WEATHER_H
#define APIXU_DEV_CURRENT_WEATHER_H

#include "include/nlohmann/json.hpp"
#include "Location.h"
#include "Current.h"

namespace Apixu {
    using nlohmann::json;

    class CurrentWeather {
    public:
        CurrentWeather() = default;
        virtual ~CurrentWeather() = default;

        const Location & getLocation() const;
        const Current & getCurrent() const;

    private:
        Location location;
        Current current;
        friend void from_json(const json & j, CurrentWeather & cw);
    };

    inline void from_json(const json & j, CurrentWeather& cw) {
        cw.location = j.at("location").get<Location>();
        cw.current = j.at("current").get<Current>();
    }
}

#endif //APIXU_DEV_CURRENT_WEATHER_H

