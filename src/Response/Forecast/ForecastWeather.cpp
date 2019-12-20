// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Forecast/ForecastWeather.h"

#include <vector>

#include "Apixu/Response/Forecast/ForecastDay.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            const std::vector<ForecastDay> &ForecastWeather::getForecastDay() const {
                return forecastDay;
            }
        }  // namespace Forecast
    }  // namespace Response
}  // namespace Apixu
