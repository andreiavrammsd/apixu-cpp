// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Current.h"

#include <string>

#include "Apixu/Response/CurrentCondition.h"

namespace Apixu {
    namespace Response {
        using std::string;
        using nlohmann::json;

        std::shared_ptr<int> Current::getLastUpdatedEpoch() const {
            return lastUpdatedEpoch;
        }

        const tm &Current::getLastUpdated() const {
            return lastUpdated;
        }

        std::shared_ptr<float> Current::getTempC() const {
            return tempC;
        }

        std::shared_ptr<float> Current::getTempF() const {
            return tempF;
        }

        std::shared_ptr<bool> Current::isDay() const {
            return day;
        }

        const CurrentCondition &Current::getCondition() const {
            return condition;
        }

        std::shared_ptr<float> Current::getWindMph() const {
            return windMph;
        }

        std::shared_ptr<float> Current::getWindKph() const {
            return windKph;
        }

        std::shared_ptr<int> Current::getWindDegree() const {
            return windDegree;
        }

        std::shared_ptr<string> Current::getWindDir() const {
            return windDir;
        }

        std::shared_ptr<float> Current::getPressureMb() const {
            return pressureMb;
        }

        std::shared_ptr<float> Current::getPressureIn() const {
            return pressureIn;
        }

        std::shared_ptr<float> Current::getPrecipMm() const {
            return precipMm;
        }

        std::shared_ptr<float> Current::getPrecipIn() const {
            return precipIn;
        }

        std::shared_ptr<int> Current::getHumidity() const {
            return humidity;
        }

        std::shared_ptr<int> Current::getCloud() const {
            return cloud;
        }

        std::shared_ptr<float> Current::getFeelslikeC() const {
            return feelslikeC;
        }

        std::shared_ptr<float> Current::getFeelslikeF() const {
            return feelslikeF;
        }

        std::shared_ptr<float> Current::getVisKm() const {
            return visKm;
        }

        std::shared_ptr<float> Current::getVisMiles() const {
            return visMiles;
        }

        std::shared_ptr<float> Current::getUv() const {
            return uv;
        }

        std::shared_ptr<float> Current::getGustMph() const {
            return gustMph;
        }

        std::shared_ptr<float> Current::getGustKph() const {
            return gustKph;
        }
    }  // namespace Response
}  // namespace Apixu
