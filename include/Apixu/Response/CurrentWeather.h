// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_
#define INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_

#include "Apixu/Response/Current.h"
#include "Apixu/Response/Location.h"
#include "nlohmann/json.hpp"

namespace Apixu {
namespace Response {
class CurrentWeather {
   public:
    const Location &getLocation() const;

    const Current &getCurrent() const;

    virtual ~CurrentWeather() = default;

   private:
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
}  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENTWEATHER_H_
