// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_

#include <string>
#include <vector>

#include "Apixu/Response/Forecast/astro.h"
#include "Apixu/Response/Forecast/day.h"
#include "Apixu/Response/Forecast/hour.h"
#include "nlohmann/json.hpp"

namespace apixu {
namespace response {
namespace forecast {
struct ForecastDay {
    std::string date;
    time_t date_epoch;
    Day day;
    Astro astro;
    std::vector<Hour> hour;

    friend void from_json(const nlohmann::json &j, ForecastDay &f);  // NOLINT
};

inline void from_json(const nlohmann::json &j, ForecastDay &f)
{  // NOLINT
    f.date = j.at("date");
    f.date_epoch = j.at("date_epoch");
    f.day = j.at("day");
    f.astro = j.at("astro");

    if (j.contains("hour")) {
        f.hour = j.at("hour").get<std::vector<Hour>>();
    }
}
}  // namespace forecast
}  // namespace response
}  // namespace apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_