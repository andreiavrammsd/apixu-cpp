#ifndef APIXU_DEV_CURRENT_WEATHER_H
#define APIXU_DEV_CURRENT_WEATHER_H

#include "../include/nlohmann/json.hpp"
#include "Location.cpp"
#include "Current.cpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;

        class CurrentWeather {
        public:
            CurrentWeather() = default;

            virtual ~CurrentWeather() = default;

            const Location &getLocation() const {
                return location;
            }

            const Current &getCurrent() const {
                return current;
            }

        private:
            Location location;
            Current current;

            friend void from_json(const json &j, CurrentWeather &cw);
        };

        inline void from_json(const json &j, CurrentWeather &cw) {
            cw.location = j.at("location").get<Location>();
            cw.current = j.at("current").get<Current>();
        }
    }
}

#endif //APIXU_DEV_CURRENT_WEATHER_H
