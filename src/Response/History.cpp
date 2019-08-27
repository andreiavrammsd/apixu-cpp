#ifndef APIXU_HISTORY_CPP
#define APIXU_HISTORY_CPP


#include "../../include/nlohmann/json.hpp"
#include "Location.cpp"
#include "Forecast/ForecastWeather.cpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;
        using Apixu::Response::Location;
        using Apixu::Response::Forecast::ForecastWeather;

        class History {
        public:
            const Location &getLocation() const {
                return location;
            }

            const ForecastWeather &getForecast() const {
                return forecast;
            }

        private:
            Location location;
            ForecastWeather forecast;

            friend void from_json(const json &j, History &h);
        };

        inline void from_json(const json &j, History &h) {
            h.location = j.at("location").get<Location>();
            h.forecast = j.at("forecast").get<ForecastWeather>();
        }
    }
}

#endif //APIXU_HISTORY_CPP
