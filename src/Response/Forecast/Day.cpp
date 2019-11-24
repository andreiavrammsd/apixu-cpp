#include "Day.hpp"
#include "../CurrentCondition.hpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            float Day::getMaxTempCelsius() const {
                return maxTempCelsius;
            }

            float Day::getMaxTempFahrenheit() const {
                return maxTempFahrenheit;
            }

            float Day::getMinTempCelsius() const {
                return minTempCelsius;
            }

            float Day::getMinTempFahrenheit() const {
                return minTempFahrenheit;
            }

            float Day::getAvgTempCelsius() const {
                return avgTempCelsius;
            }

            float Day::getAvgTempFahrenheit() const {
                return avgTempFahrenheit;
            }

            float Day::getMaxWindMph() const {
                return maxWindMPH;
            }

            float Day::getMaxWindKph() const {
                return maxWindKPH;
            }

            float Day::getTotalPrecipMm() const {
                return totalPrecipMM;
            }

            float Day::getTotalPrecipIn() const {
                return totalPrecipIN;
            }

            float Day::getAvgVisKm() const {
                return avgVisKM;
            }

            float Day::getAvgVisMiles() const {
                return avgVisMiles;
            }

            float Day::getAvgHumidity() const {
                return avgHumidity;
            }

            const CurrentCondition &Day::getCondition() const {
                return condition;
            }

            float Day::getUv() const {
                return uv;
            }
        }
    }
}
