#ifndef APIXU_RESPONSE_CURRENT_WEATHER_HPP_
#define APIXU_RESPONSE_CURRENT_WEATHER_HPP_

#include "Location.hpp"
#include "Current.hpp"
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;

        class CurrentWeather {
        public:
            const Location &getLocation() const;

            const Current &getCurrent() const;

            virtual ~CurrentWeather() = default;

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

#endif // APIXU_RESPONSE_CURRENT_WEATHER_HPP_