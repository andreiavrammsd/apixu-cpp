#ifndef APIXU_RESPONSE_CURRENT_WEATHER_HPP_
#define APIXU_RESPONSE_CURRENT_WEATHER_HPP_

#include "Apixu/Response/Location.hpp"
#include "Apixu/Response/Current.hpp"
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
            cw.location = j.at("location");
            cw.current = j.at("current");
        }
    }
}

#endif // APIXU_RESPONSE_CURRENT_WEATHER_HPP_
