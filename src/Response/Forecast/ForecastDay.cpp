#include "Apixu/Response/Forecast/ForecastDay.h"

#include "Apixu/Response/Forecast/Day.h"
#include "Apixu/Response/Forecast/Astro.h"
#include "Apixu/Response/Forecast/Hour.h"

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
