#include "Apixu/Response/Current.h"

#include "Apixu/Time.h"
#include "Apixu/Response/CurrentCondition.h"

namespace Apixu {
    namespace Response {
        using std::string;
        using nlohmann::json;

        int *Current::getLastUpdatedEpoch() const {
            return lastUpdatedEpoch;
        }

        const tm &Current::getLastUpdated() const {
            return lastUpdated;
        }

        float *Current::getTempC() const {
            return tempC;
        }

        float *Current::getTempF() const {
            return tempF;
        }

        bool *Current::isDay() const {
            return day;
        }

        const CurrentCondition &Current::getCondition() const {
            return condition;
        }

        float *Current::getWindMph() const {
            return windMph;
        }

        float *Current::getWindKph() const {
            return windKph;
        }

        int *Current::getWindDegree() const {
            return windDegree;
        }

        string *Current::getWindDir() const {
            return windDir;
        }

        float *Current::getPressureMb() const {
            return pressureMb;
        }

        float *Current::getPressureIn() const {
            return pressureIn;
        }

        float *Current::getPrecipMm() const {
            return precipMm;
        }

        float *Current::getPrecipIn() const {
            return precipIn;
        }

        int *Current::getHumidity() const {
            return humidity;
        }

        int *Current::getCloud() const {
            return cloud;
        }

        float *Current::getFeelslikeC() const {
            return feelslikeC;
        }

        float *Current::getFeelslikeF() const {
            return feelslikeF;
        }

        float *Current::getVisKm() const {
            return visKm;
        }

        float *Current::getVisMiles() const {
            return visMiles;
        }

        float *Current::getUv() const {
            return uv;
        }

        float *Current::getGustMph() const {
            return gustMph;
        }

        float *Current::getGustKph() const {
            return gustKph;
        }
    }
}
