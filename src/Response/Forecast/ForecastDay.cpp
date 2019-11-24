#include "ForecastDay.hpp"
#include "Day.hpp"
#include "Astro.hpp"
#include "Hour.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using std::string;
            using std::vector;

            const string &ForecastDay::getDate() const {
                return date;
            }

            time_t ForecastDay::getDateEpoch() const {
                return dateEpoch;
            }

            const Day &ForecastDay::getDay() const {
                return day;
            }

            const Astro &ForecastDay::getAstro() const {
                return astro;
            }

            const vector<Hour> &ForecastDay::getHour() const {
                return hour;
            }
        }
    }
}
