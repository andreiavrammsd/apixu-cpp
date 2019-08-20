#ifndef APIXU_CURRENT_WEATHER_CPP
#define APIXU_CURRENT_WEATHER_CPP

#include "../../include/nlohmann/json.hpp"
#include "Location.cpp"
#include "Current.cpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;

        class CurrentWeather {
        public:
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

#endif //APIXU_CURRENT_WEATHER_CPP
