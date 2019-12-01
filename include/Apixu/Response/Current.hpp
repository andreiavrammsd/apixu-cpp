#ifndef APIXU_RESPONSE_CURRENT_HPP_
#define APIXU_RESPONSE_CURRENT_HPP_


#include "Apixu/Time.hpp"
#include "CurrentCondition.hpp"

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
                c.day = new bool(j.at("is_day").get<int>());
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

#endif // APIXU_RESPONSE_CURRENT_HPP_
