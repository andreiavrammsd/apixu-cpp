#ifndef APIXU_FORECAST_DAY_CPP
#define APIXU_FORECAST_DAY_CPP

#include "../../../include/nlohmann/json.hpp"
#include "Day.cpp"
#include "Astro.cpp"
#include "Hour.cpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::string;

            class ForecastDay {
            public:
                const string &getDate() const {
                    return date;
                }

                time_t getDateEpoch() const {
                    return dateEpoch;
                }

                const Day &getDay() const {
                    return day;
                }

                const Astro &getAstro() const {
                    return astro;
                }

                const vector<Hour> &getHour() const {
                    return hour;
                }

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

#endif //APIXU_FORECAST_DAY_CPP
