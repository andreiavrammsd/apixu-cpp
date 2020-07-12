// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_
#define INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_

#include "Apixu/Response/current.h"
#include "Apixu/Response/location.h"
#include "nlohmann/json.hpp"

namespace apixu {
namespace response {
struct CurrentWeather {
    Location location;
    Current current;

    friend void from_json(const nlohmann::json &j,
                          CurrentWeather &cw);  // NOLINT
};

inline void from_json(const nlohmann::json &j, CurrentWeather &cw)
{  // NOLINT
    cw.location = j.at("location");
    cw.current = j.at("current");
}
}  // namespace response
}  // namespace apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_
