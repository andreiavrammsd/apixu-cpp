#include "Apixu/Response/Forecast/ForecastWeather.hpp"
#include "Apixu/Response/Forecast/ForecastDay.hpp"

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
