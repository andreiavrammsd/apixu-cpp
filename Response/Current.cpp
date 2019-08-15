#ifndef APIXU_DEV_CURRENT_CPP
#define APIXU_DEV_CURRENT_CPP


#include "../include/nlohmann/json.hpp"
#include "../Time.h"
#include "CurrentCondition.cpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    namespace Response {
        class Current {
        public:
            Current() = default;

            virtual ~Current() = default;

            int *getLastUpdatedEpoch() const {
                return lastUpdatedEpoch;
            }

            const tm &getLastUpdated() const {
                return lastUpdated;
            }

            float *getTempC() const {
                return tempC;
            }

            float *getTempF() const {
                return tempF;
            }

            bool *getIsDay() const {
                return isDay;
            }

            const CurrentCondition &getCondition() const {
                return condition;
            }

            float *getWindMph() const {
                return windMph;
            }

            float *getWindKph() const {
                return windKph;
            }

            int *getWindDegree() const {
                return windDegree;
            }

            string *getWindDir() const {
                return windDir;
            }

            float *getPressureMb() const {
                return pressureMb;
            }

            float *getPressureIn() const {
                return pressureIn;
            }

            float *getPrecipMm() const {
                return precipMm;
            }

            float *getPrecipIn() const {
                return precipIn;
            }

            int *getHumidity() const {
                return humidity;
            }

            int *getCloud() const {
                return cloud;
            }

            float *getFeelslikeC() const {
                return feelslikeC;
            }

            float *getFeelslikeF() const {
                return feelslikeF;
            }

            float *getVisKm() const {
                return visKm;
            }

            float *getVisMiles() const {
                return visMiles;
            }

            float *getUv() const {
                return uv;
            }

            float *getGustMph() const {
                return gustMph;
            }

            float *getGustKph() const {
                return gustKph;
            }

        private:
            int *lastUpdatedEpoch{};
            struct tm lastUpdated{};
            float *tempC{};
            float *tempF{};
            bool *isDay{};
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

            friend void from_json(const json &j, Current &c);
        };

        inline void from_json(const json &j, Current &c) {
            if (j.contains("last_updated_epoch")) {
                c.lastUpdatedEpoch = new int(j.at("last_updated_epoch").get<int>());
            }

            if (j.contains("last_updated")) {
                c.lastUpdated = Time::parse(j.at("last_updated").get<string>());
            }

            if (j.contains("temp_c")) {
                c.tempC = new float(j.at("temp_c").get<float>());
            }

            if (j.contains("temp_f")) {
                c.tempF = new float(j.at("temp_f").get<float>());
            }

            if (j.contains("is_day")) {
                c.isDay = new bool(j.at("is_day").get<int>());
            }

            c.condition = j.at("condition").get<CurrentCondition>();

            if (j.contains("wind_mph")) {
                c.windMph = new float(j.at("wind_mph").get<float>());
            }

            if (j.contains("wind_kph")) {
                c.windKph = new float(j.at("wind_kph").get<float>());
            }

            if (j.contains("wind_degree")) {
                c.windDegree = new int(j.at("wind_degree").get<int>());
            }

            if (j.contains("wind_dir")) {
                c.windDir = new string(j.at("wind_dir").get<string>());
            }

            if (j.contains("pressure_mb")) {
                c.pressureMb = new float(j.at("pressure_mb").get<float>());
            }

            if (j.contains("pressure_in")) {
                c.pressureIn = new float(j.at("pressure_in").get<float>());
            }

            if (j.contains("precip_mm")) {
                c.precipMm = new float(j.at("precip_mm").get<float>());
            }

            if (j.contains("precip_in")) {
                c.precipIn = new float(j.at("precip_in").get<float>());
            }

            if (j.contains("humidity")) {
                c.humidity = new int(j.at("humidity").get<int>());
            }

            if (j.contains("cloud")) {
                c.cloud = new int(j.at("cloud").get<int>());
            }

            if (j.contains("feelslike_c")) {
                c.feelslikeC = new float(j.at("feelslike_c").get<float>());
            }

            if (j.contains("feelslike_f")) {
                c.feelslikeF = new float(j.at("feelslike_f").get<float>());
            }

            if (j.contains("vis_km")) {
                c.visKm = new float(j.at("vis_km").get<float>());
            }

            if (j.contains("vis_miles")) {
                c.visMiles = new float(j.at("vis_miles").get<float>());
            }

            if (j.contains("uv")) {
                c.uv = new float(j.at("uv").get<float>());
            }

            if (j.contains("gust_mph")) {
                c.gustMph = new float(j.at("gust_mph").get<float>());
            }

            if (j.contains("gust_kph")) {
                c.gustKph = new float(j.at("gust_kph").get<float>());
            }
        }
    }
}

#endif //APIXU_DEV_CURRENT_CPP
