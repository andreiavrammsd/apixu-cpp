#ifndef APIXU_RESPONSE_FORECAST_ASTRO_HPP_
#define APIXU_RESPONSE_FORECAST_ASTRO_HPP_

#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::string;

            class Astro {
            public:
                const string &getSunrise() const;

                const string &getSunset() const;

                const string &getMoonrise() const;

                const string &getMoonset() const;

                const string &getMoonPhase() const;

                const string &getMoonIllumination() const;

                virtual ~Astro() = default;

            private:
                string sunrise;
                string sunset;
                string moonrise;
                string moonset;
                string moonPhase;
                string moonIllumination;

                friend void from_json(const json &j, Astro &d);
            };

            inline void from_json(const json &j, Astro &d) {
                if (j.contains("sunrise")) {
                    d.sunrise = j.at("sunrise").get<string>();
                }

                if (j.contains("sunset")) {
                    d.sunset = j.at("sunset").get<string>();
                }

                if (j.contains("moonrise")) {
                    d.moonrise = j.at("moonrise").get<string>();
                }

                if (j.contains("moonset")) {
                    d.moonset = j.at("moonset").get<string>();
                }

                if (j.contains("moon_phase")) {
                    d.moonPhase = j.at("moon_phase").get<string>();
                }

                if (j.contains("moon_illumination")) {
                    d.moonIllumination = j.at("moon_illumination").get<string>();
                }
            }
        }
    }
}

#endif // APIXU_RESPONSE_FORECAST_ASTRO_HPP_
