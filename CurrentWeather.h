#ifndef APIXU_DEV_CURRENT_WEATHER_H
#define APIXU_DEV_CURRENT_WEATHER_H

#include "include/nlohmann/json.hpp"
#include "Location.h"

namespace Apixu {
    using nlohmann::json;

    class CurrentWeather {
    public:
        CurrentWeather() = default;
        virtual ~CurrentWeather() = default;

    private:
        Location location;
        friend void from_json(const json & j, CurrentWeather & cw);

    public:
        const Location & getLocation() const;
    };

    inline void from_json(const json & j, CurrentWeather& cw) {
        cw.location = j.at("location").get<Location>();
    }
}

#endif //APIXU_DEV_CURRENT_WEATHER_H

