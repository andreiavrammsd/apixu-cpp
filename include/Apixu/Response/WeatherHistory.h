#ifndef APIXU_RESPONSE_HISTORY_H_
#define APIXU_RESPONSE_HISTORY_H_


#include "nlohmann/json.hpp"
#include "Apixu/Response/Location.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"

namespace Apixu {
    namespace Response {
        using nlohmann::json;
        using Apixu::Response::Location;
        using Apixu::Response::Forecast::ForecastWeather;

        class WeatherHistory {
        public:
            const Location &getLocation() const;

            const ForecastWeather &getForecast() const;

            virtual ~WeatherHistory() = default;

        private:
            Location location;
            ForecastWeather forecast;

            friend void from_json(const json &j, WeatherHistory &h);
        };

        inline void from_json(const json &j, WeatherHistory &h) {
            h.location = j.at("location");
            h.forecast = j.at("forecast");
        }
    }
}

#endif // APIXU_RESPONSE_HISTORY_H_
