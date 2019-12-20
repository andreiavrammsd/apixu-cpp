// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_FORECAST_DAY_H_
#define INCLUDE_APIXU_RESPONSE_FORECAST_DAY_H_

#include "nlohmann/json.hpp"
#include "Apixu/Response/CurrentCondition.h"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            class Day {
            public:
                float getMaxTempCelsius() const;

                float getMaxTempFahrenheit() const;

                float getMinTempCelsius() const;

                float getMinTempFahrenheit() const;

                float getAvgTempCelsius() const;

                float getAvgTempFahrenheit() const;

                float getMaxWindMph() const;

                float getMaxWindKph() const;

                float getTotalPrecipMm() const;

                float getTotalPrecipIn() const;

                float getAvgVisKm() const;

                float getAvgVisMiles() const;

                float getAvgHumidity() const;

                const CurrentCondition &getCondition() const;

                float getUv() const;

                virtual ~Day() = default;

            private:
                float maxTempCelsius{};
                float maxTempFahrenheit{};
                float minTempCelsius{};
                float minTempFahrenheit{};
                float avgTempCelsius{};
                float avgTempFahrenheit{};
                float maxWindMPH{};
                float maxWindKPH{};
                float totalPrecipMM{};
                float totalPrecipIN{};
                float avgVisKM{};
                float avgVisMiles{};
                float avgHumidity{};
                CurrentCondition condition;
                float uv{};

                friend void from_json(const nlohmann::json &j, Day &d); // NOLINT
            };

            inline void from_json(const nlohmann::json &j, Day &d) { // NOLINT
                if (j.contains("maxtemp_c")) {
                    d.maxTempCelsius = j.at("maxtemp_c");
                }

                if (j.contains("maxtemp_f")) {
                    d.maxTempFahrenheit = j.at("maxtemp_f");
                }

                if (j.contains("mintemp_c")) {
                    d.minTempCelsius = j.at("mintemp_c");
                }

                if (j.contains("mintemp_f")) {
                    d.minTempFahrenheit = j.at("mintemp_f");
                }

                if (j.contains("avgtemp_c")) {
                    d.avgTempCelsius = j.at("avgtemp_c");
                }

                if (j.contains("avgtemp_f")) {
                    d.avgTempFahrenheit = j.at("avgtemp_f");
                }

                if (j.contains("maxwind_mph")) {
                    d.maxWindMPH = j.at("maxwind_mph");
                }

                if (j.contains("maxwind_kph")) {
                    d.maxWindKPH = j.at("maxwind_kph");
                }

                if (j.contains("totalprecip_mm")) {
                    d.totalPrecipMM = j.at("totalprecip_mm");
                }

                if (j.contains("totalprecip_in")) {
                    d.totalPrecipIN = j.at("totalprecip_in");
                }

                if (j.contains("avgvis_km")) {
                    d.avgVisKM = j.at("avgvis_km");
                }

                if (j.contains("avgvis_miles")) {
                    d.avgVisMiles = j.at("avgvis_miles");
                }

                if (j.contains("avghumidity")) {
                    d.avgHumidity = j.at("avghumidity");
                }

                if (j.contains("condition")) {
                    d.condition = j.at("condition");
                }

                if (j.contains("uv")) {
                    d.uv = j.at("uv");
                }
            }
        }  // namespace Forecast
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_FORECAST_DAY_H_
