#include "ForecastWeather.hpp"
#include "ForecastDay.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using std::vector;

            const vector<ForecastDay> &ForecastWeather::getForecastDay() const {
                return forecastDay;
            }
        }
    }
}
