// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Forecast/ForecastDay.h"

#include <string>
#include <vector>

#include "Apixu/Response/Forecast/Astro.h"
#include "Apixu/Response/Forecast/Day.h"
#include "Apixu/Response/Forecast/Hour.h"

namespace Apixu {
namespace Response {
namespace Forecast {
const std::string &ForecastDay::getDate() const { return date; }

time_t ForecastDay::getDateEpoch() const { return dateEpoch; }

const Day &ForecastDay::getDay() const { return day; }

const Astro &ForecastDay::getAstro() const { return astro; }

const std::vector<Hour> &ForecastDay::getHour() const { return hour; }
}  // namespace Forecast
}  // namespace Response
}  // namespace Apixu
