#ifndef APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_HPP_
#define APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_HPP_

#include "Apixu/Response/Location.hpp"
#include "Apixu/Response/Current.hpp"
#include "Apixu/Response/Forecast/ForecastWeather.hpp"
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            class WeatherForecast {
            public:
                const Location &getLocation() const;

                const Current &getCurrent() const;

                const ForecastWeather &getForecast() const;

                virtual ~WeatherForecast() = default;

            private:
                Location location;
                Current current;
                ForecastWeather forecast{};

                friend void from_json(const json &j, WeatherForecast &f);
            };

            inline void from_json(const json &j, WeatherForecast &f) {
                f.location = j.at("location");
                f.current = j.at("current");
                f.forecast = j.at("forecast");
            }
        }
    }
}

#endif // APIXU_RESPONSE_FORECAST_WEATHER_FORECAST_HPP_
