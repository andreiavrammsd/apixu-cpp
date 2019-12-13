#ifndef APIXU_RESPONSE_FORECAST_FORECAST_DAY_H_
#define APIXU_RESPONSE_FORECAST_FORECAST_DAY_H_

#include "nlohmann/json.hpp"
#include "Apixu/Response/Forecast/Day.h"
#include "Apixu/Response/Forecast/Astro.h"
#include "Apixu/Response/Forecast/Hour.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::string;
            using std::vector;

            class ForecastDay {
            public:
                const string &getDate() const;

                time_t getDateEpoch() const;

                const Day &getDay() const;

                const Astro &getAstro() const;

                const vector<Hour> &getHour() const;

                virtual ~ForecastDay() = default;

            private:
                string date;
                time_t dateEpoch;
                Day day;
                Astro astro;
                vector<Hour> hour;

                friend void from_json(const json &j, ForecastDay &f);
            };

            inline void from_json(const json &j, ForecastDay &f) {
                f.date = j.at("date");
                f.dateEpoch = j.at("date_epoch");
                f.day = j.at("day");
                f.astro = j.at("astro");

                if (j.contains("hour")) {
                    f.hour = j.at("hour").get<vector<Hour>>();
                }
            }
        }
    }
}

#endif // APIXU_RESPONSE_FORECAST_FORECAST_DAY_H_