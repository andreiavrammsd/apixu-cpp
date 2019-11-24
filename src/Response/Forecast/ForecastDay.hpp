#ifndef APIXU_RESPONSE_FORECAST_FORECAST_DAY_HPP_
#define APIXU_RESPONSE_FORECAST_FORECAST_DAY_HPP_

#include "nlohmann/json.hpp"
#include "Day.hpp"
#include "Astro.hpp"
#include "Hour.hpp"

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
                f.date = j.at("date").get<string>();
                f.dateEpoch = j.at("date_epoch").get<time_t>();
                f.day = j.at("day").get<Day>();
                f.astro = j.at("astro").get<Astro>();

                if (j.contains("hour")) {
                    f.hour = j.at("hour").get<vector<Hour>>();
                }
            }
        }
    }
}

#endif // APIXU_RESPONSE_FORECAST_FORECAST_DAY_HPP_
