// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_

#include <string>
#include <vector>

#include "nlohmann/json.hpp"
#include "Apixu/Response/Forecast/Day.h"
#include "Apixu/Response/Forecast/Astro.h"
#include "Apixu/Response/Forecast/Hour.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            class ForecastDay {
            public:
                const std::string &getDate() const;

                time_t getDateEpoch() const;

                const Day &getDay() const;

                const Astro &getAstro() const;

                const std::vector<Hour> &getHour() const;

                virtual ~ForecastDay() = default;

            private:
                std::string date;
                time_t dateEpoch;
                Day day;
                Astro astro;
                std::vector<Hour> hour;

                friend void from_json(const nlohmann::json &j, ForecastDay &f); // NOLINT
            };

            inline void from_json(const nlohmann::json &j, ForecastDay &f) { // NOLINT
                f.date = j.at("date");
                f.dateEpoch = j.at("date_epoch");
                f.day = j.at("day");
                f.astro = j.at("astro");

                if (j.contains("hour")) {
                    f.hour = j.at("hour").get<std::vector<Hour>>();
                }
            }
        }  // namespace Forecast
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_FORECASTDAY_H_
