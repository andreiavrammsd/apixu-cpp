#ifndef APIXU_RESPONSE_FORECAST_FORECAST_HPP_
#define APIXU_RESPONSE_FORECAST_FORECAST_HPP_

#include "../Location.hpp"
#include "../Current.hpp"
#include "ForecastWeather.hpp"
#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            class Forecast {
            public:
                const Location &getLocation() const;

                const Current &getCurrent() const;

                const ForecastWeather &getForecast() const;

                virtual ~Forecast() = default;

            private:
                Location location;
                Current current;
                ForecastWeather forecast{};

                friend void from_json(const json &j, Forecast &f);
            };

            inline void from_json(const json &j, Forecast &f) {
                f.location = j.at("location").get<Location>();
                f.current = j.at("current").get<Current>();
                f.forecast = j.at("forecast").get<ForecastWeather>();
            }
        }
    }
}

#endif // APIXU_RESPONSE_FORECAST_FORECAST_HPP_
