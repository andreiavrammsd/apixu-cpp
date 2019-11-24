#ifndef APIXU_RESPONSE_HISTORY_HPP_
#define APIXU_RESPONSE_HISTORY_HPP_


#include "Location.hpp"
#include "Forecast/ForecastWeather.hpp"
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        using nlohmann::json;
        using Apixu::Response::Location;
        using Apixu::Response::Forecast::ForecastWeather;

        class History {
        public:
            const Location &getLocation() const;

            const ForecastWeather &getForecast() const;

            virtual ~History() = default;

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

#endif // APIXU_RESPONSE_HISTORY_HPP_
