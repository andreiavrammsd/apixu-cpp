#include "Current.h"

namespace Apixu {
    int *Apixu::Current::getLastUpdatedEpoch() const {
        return lastUpdatedEpoch;
    }

    const tm &Apixu::Current::getLastUpdated() const {
        return lastUpdated;
    }

    float *Apixu::Current::getTempC() const {
        return tempC;
    }

    float *Apixu::Current::getTempF() const {
        return tempF;
    }

    bool *Apixu::Current::getIsDay() const {
        return isDay;
    }

    const Apixu::CurrentCondition &Apixu::Current::getCondition() const {
        return condition;
    }

    float *Apixu::Current::getWindMph() const {
        return windMph;
    }

    float *Apixu::Current::getWindKph() const {
        return windKph;
    }

    int *Apixu::Current::getWindDegree() const {
        return windDegree;
    }

    string *Apixu::Current::getWindDir() const {
        return windDir;
    }

    float *Apixu::Current::getPressureMb() const {
        return pressureMb;
    }

    float *Apixu::Current::getPressureIn() const {
        return pressureIn;
    }

    float *Apixu::Current::getPrecipMm() const {
        return precipMm;
    }

    float *Apixu::Current::getPrecipIn() const {
        return precipIn;
    }

    int *Apixu::Current::getHumidity() const {
        return humidity;
    }

    int *Apixu::Current::getCloud() const {
        return cloud;
    }

    float *Apixu::Current::getFeelslikeC() const {
        return feelslikeC;
    }

    float *Apixu::Current::getFeelslikeF() const {
        return feelslikeF;
    }

    float *Apixu::Current::getVisKm() const {
        return visKm;
    }

    float *Apixu::Current::getVisMiles() const {
        return visMiles;
    }

    float *Apixu::Current::getUv() const {
        return uv;
    }

    float *Apixu::Current::getGustMph() const {
        return gustMph;
    }

    float *Apixu::Current::getGustKph() const {
        return gustKph;
    }
}
