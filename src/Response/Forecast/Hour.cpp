// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Forecast/Hour.h"

#include <string>

namespace Apixu {
namespace Response {
namespace Forecast {
time_t Hour::getTimeEpoch() const { return timeEpoch; }

const std::string &Hour::getTime() const { return time; }

double Hour::getTempC() const { return tempC; }

double Hour::getTempF() const { return tempF; }

bool Hour::isDay() const { return day; }

const CurrentCondition &Hour::getCondition() const { return condition; }

double Hour::getWindMph() const { return windMph; }

double Hour::getWindKph() const { return windKph; }

int64_t Hour::getWindDegree() const { return windDegree; }

const std::string &Hour::getWindDir() const { return windDir; }

int64_t Hour::getPressureMb() const { return pressureMb; }

double Hour::getPressureIn() const { return pressureIn; }

double Hour::getPrecipMm() const { return precipMm; }

double Hour::getPrecipIn() const { return precipIn; }

int64_t Hour::getHumidity() const { return humidity; }

int64_t Hour::getCloud() const { return cloud; }

double Hour::getFeelsLikeC() const { return feelsLikeC; }

double Hour::getFeelsLikeF() const { return feelsLikeF; }

double Hour::getWindChillC() const { return windChillC; }

double Hour::getWindChillF() const { return windChillF; }

double Hour::getHeatIndexC() const { return heatIndexC; }

double Hour::getHeatIndexF() const { return heatIndexF; }

double Hour::getDewPointC() const { return dewpointC; }

double Hour::getDewPointF() const { return dewPointF; }

bool Hour::willItRain() const { return willRain; }

const std::string &Hour::getChanceOfRain() const { return chanceOfRain; }

bool Hour::willItSnow() const { return willSnow; }

const std::string &Hour::getChanceOfSnow() const { return chanceOfSnow; }

int64_t Hour::getVisKm() const { return visKm; }

int64_t Hour::getVisMiles() const { return visMiles; }

double Hour::getGustMph() const { return gustMph; }

double Hour::getGustKph() const { return gustKph; }
}  // namespace Forecast
}  // namespace Response
}  // namespace Apixu
