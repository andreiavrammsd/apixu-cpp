#ifndef APIXU_FORECAST_CPP
#define APIXU_FORECAST_CPP

#include "../../../include/nlohmann/json.hpp"
#include "../Location.cpp"
#include "../Current.cpp"
#include "ForecastWeather.cpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            class Forecast {
            public:
                const Location &getLocation() const {
                    return location;
                }

                const Current &getCurrent() const {
                    return current;
                }

                const ForecastWeather &getForecast() const {
                    return forecast;
                }

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

#endif //APIXU_FORECAST_CPP
