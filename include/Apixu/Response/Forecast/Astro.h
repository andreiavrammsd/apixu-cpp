// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_ASTRO_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_ASTRO_H_

#include <string>

#include "nlohmann/json.hpp"

namespace Apixu {
namespace Response {
namespace Forecast {
class Astro {
   public:
    const std::string &getSunrise() const;

    const std::string &getSunset() const;

    const std::string &getMoonrise() const;

    const std::string &getMoonset() const;

    const std::string &getMoonPhase() const;

    const std::string &getMoonIllumination() const;

    virtual ~Astro() = default;

   private:
    std::string sunrise;
    std::string sunset;
    std::string moonrise;
    std::string moonset;
    std::string moonPhase;
    std::string moonIllumination;

    friend void from_json(const nlohmann::json &j, Astro &d);  // NOLINT
};

inline void from_json(const nlohmann::json &j, Astro &d)
{  // NOLINT
    if (j.contains("sunrise")) {
        d.sunrise = j.at("sunrise");
    }

    if (j.contains("sunset")) {
        d.sunset = j.at("sunset");
    }

    if (j.contains("moonrise")) {
        d.moonrise = j.at("moonrise");
    }

    if (j.contains("moonset")) {
        d.moonset = j.at("moonset");
    }

    if (j.contains("moon_phase")) {
        d.moonPhase = j.at("moon_phase");
    }

    if (j.contains("moon_illumination")) {
        d.moonIllumination = j.at("moon_illumination");
    }
}
}  // namespace Forecast
}  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_ASTRO_H_
