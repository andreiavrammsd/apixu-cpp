#ifndef APIXU_DAY_CPP
#define APIXU_DAY_CPP

#include "../../../include/nlohmann/json.hpp"
#include "../CurrentCondition.cpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;
            using std::string;

            class Day {
            public:
                float getMaxTempCelsius() const {
                    return maxTempCelsius;
                }

                float getMaxTempFahrenheit() const {
                    return maxTempFahrenheit;
                }

                float getMinTempCelsius() const {
                    return minTempCelsius;
                }

                float getMinTempFahrenheit() const {
                    return minTempFahrenheit;
                }

                float getAvgTempCelsius() const {
                    return avgTempCelsius;
                }

                float getAvgTempFahrenheit() const {
                    return avgTempFahrenheit;
                }

                float getMaxWindMph() const {
                    return maxWindMPH;
                }

                float getMaxWindKph() const {
                    return maxWindKPH;
                }

                float getTotalPrecipMm() const {
                    return totalPrecipMM;
                }

                float getTotalPrecipIn() const {
                    return totalPrecipIN;
                }

                float getAvgVisKm() const {
                    return avgVisKM;
                }

                float getAvgVisMiles() const {
                    return avgVisMiles;
                }

                float getAvgHumidity() const {
                    return avgHumidity;
                }

                const CurrentCondition &getCondition() const {
                    return condition;
                }

                float getUv() const {
                    return uv;
                }

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

                friend void from_json(const json &j, Day &d);
            };

            inline void from_json(const json &j, Day &d) {
                if (j.contains("maxtemp_c")) {
                    d.maxTempCelsius = j.at("maxtemp_c").get<float>();
                }

                if (j.contains("maxtemp_f")) {
                    d.maxTempFahrenheit = j.at("maxtemp_f").get<float>();
                }

                if (j.contains("mintemp_c")) {
                    d.minTempCelsius = j.at("mintemp_c").get<float>();
                }

                if (j.contains("mintemp_f")) {
                    d.minTempFahrenheit = j.at("mintemp_f").get<float>();
                }

                if (j.contains("avgtemp_c")) {
                    d.avgTempCelsius = j.at("avgtemp_c").get<float>();
                }

                if (j.contains("avgtemp_f")) {
                    d.avgTempFahrenheit = j.at("avgtemp_f").get<float>();
                }

                if (j.contains("maxwind_mph")) {
                    d.maxWindMPH = j.at("maxwind_mph").get<float>();
                }

                if (j.contains("maxwind_kph")) {
                    d.maxWindKPH = j.at("maxwind_kph").get<float>();
                }

                if (j.contains("totalprecip_mm")) {
                    d.totalPrecipMM = j.at("totalprecip_mm").get<float>();
                }

                if (j.contains("totalprecip_in")) {
                    d.totalPrecipIN = j.at("totalprecip_in").get<float>();
                }

                if (j.contains("avgvis_km")) {
                    d.avgVisKM = j.at("avgvis_km").get<float>();
                }

                if (j.contains("avgvis_miles")) {
                    d.avgVisMiles = j.at("avgvis_miles").get<float>();
                }

                if (j.contains("avghumidity")) {
                    d.avgHumidity = j.at("avghumidity").get<float>();
                }

                if (j.contains("condition")) {
                    d.condition = j.at("condition").get<CurrentCondition>();
                }

                if (j.contains("uv")) {
                    d.uv = j.at("uv").get<float>();
                }
            }
        }
    }
}

#endif //APIXU_DAY_CPP
