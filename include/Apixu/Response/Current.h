// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENT_H_
#define INCLUDE_APIXU_RESPONSE_CURRENT_H_

#include <string>

#include "CurrentCondition.h"
#include "Apixu/Time.h"

namespace Apixu {
    namespace Response {
        using std::string;
        using nlohmann::json;

        class Current {
        public:
            int *getLastUpdatedEpoch() const;

            const tm &getLastUpdated() const;

            float *getTempC() const;

            float *getTempF() const;

            bool *isDay() const;

            const CurrentCondition &getCondition() const;

            float *getWindMph() const;

            float *getWindKph() const;

            int *getWindDegree() const;

            string *getWindDir() const;

            float *getPressureMb() const;

            float *getPressureIn() const;

            float *getPrecipMm() const;

            float *getPrecipIn() const;

            int *getHumidity() const;

            int *getCloud() const;

            float *getFeelslikeC() const;

            float *getFeelslikeF() const;

            float *getVisKm() const;

            float *getVisMiles() const;

            float *getUv() const;

            float *getGustMph() const;

            float *getGustKph() const;

            virtual ~Current() = default;

        private:
            int *lastUpdatedEpoch{};
            struct tm lastUpdated{};
            float *tempC{};
            float *tempF{};
            bool *day{};
            CurrentCondition condition;
            float *windMph{};
            float *windKph{};
            int *windDegree{};
            string *windDir{};
            float *pressureMb{};
            float *pressureIn{};
            float *precipMm{};
            float *precipIn{};
            int *humidity{};
            int *cloud{};
            float *feelslikeC{};
            float *feelslikeF{};
            float *visKm{};
            float *visMiles{};
            float *uv{};
            float *gustMph{};
            float *gustKph{};

            friend void from_json(const json &j, Current &c); // NOLINT
        };

        inline void from_json(const json &j, Current &c) { // NOLINT
            if (j.contains("last_updated_epoch")) {
                c.lastUpdatedEpoch = new int(j.at("last_updated_epoch"));
            }

            if (j.contains("last_updated")) {
                c.lastUpdated = Time::parse(j.at("last_updated"));
            }

            if (j.contains("temp_c")) {
                c.tempC = new float(j.at("temp_c"));
            }

            if (j.contains("temp_f")) {
                c.tempF = new float(j.at("temp_f"));
            }

            if (j.contains("is_day")) {
                c.day = new bool(j.at("is_day").get<int>());
            }

            c.condition = j.at("condition");

            if (j.contains("wind_mph")) {
                c.windMph = new float(j.at("wind_mph"));
            }

            if (j.contains("wind_kph")) {
                c.windKph = new float(j.at("wind_kph"));
            }

            if (j.contains("wind_degree")) {
                c.windDegree = new int(j.at("wind_degree"));
            }

            if (j.contains("wind_dir")) {
                c.windDir = new string(j.at("wind_dir"));
            }

            if (j.contains("pressure_mb")) {
                c.pressureMb = new float(j.at("pressure_mb"));
            }

            if (j.contains("pressure_in")) {
                c.pressureIn = new float(j.at("pressure_in"));
            }

            if (j.contains("precip_mm")) {
                c.precipMm = new float(j.at("precip_mm"));
            }

            if (j.contains("precip_in")) {
                c.precipIn = new float(j.at("precip_in"));
            }

            if (j.contains("humidity")) {
                c.humidity = new int(j.at("humidity"));
            }

            if (j.contains("cloud")) {
                c.cloud = new int(j.at("cloud"));
            }

            if (j.contains("feelslike_c")) {
                c.feelslikeC = new float(j.at("feelslike_c"));
            }

            if (j.contains("feelslike_f")) {
                c.feelslikeF = new float(j.at("feelslike_f"));
            }

            if (j.contains("vis_km")) {
                c.visKm = new float(j.at("vis_km"));
            }

            if (j.contains("vis_miles")) {
                c.visMiles = new float(j.at("vis_miles"));
            }

            if (j.contains("uv")) {
                c.uv = new float(j.at("uv"));
            }

            if (j.contains("gust_mph")) {
                c.gustMph = new float(j.at("gust_mph"));
            }

            if (j.contains("gust_kph")) {
                c.gustKph = new float(j.at("gust_kph"));
            }
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENT_H_
