// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_
#define INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_


#include "nlohmann/json.hpp"
#include "Apixu/Response/Location.h"
#include "Apixu/Response/Forecast/ForecastWeather.h"

namespace Apixu {
    namespace Response {
        class WeatherHistory {
        public:
            const Location &getLocation() const;

            const Forecast::ForecastWeather &getForecast() const;

            virtual ~WeatherHistory() = default;

        private:
            Location location;
            Forecast::ForecastWeather forecast;

            friend void from_json(const nlohmann::json &j, WeatherHistory &h); // NOLINT
        };

        inline void from_json(const nlohmann::json &j, WeatherHistory &h) { // NOLINT
            h.location = j.at("location");
            h.forecast = j.at("forecast");
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_WEATHERHISTORY_H_
