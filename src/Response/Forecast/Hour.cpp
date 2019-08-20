#ifndef APIXU_HOUR_CPP
#define APIXU_HOUR_CPP

#include "../../../include/nlohmann/json.hpp"
#include "../CurrentCondition.cpp"

namespace Apixu {
    namespace Response {
        namespace Forecast {
            using nlohmann::json;

            class Hour {
            public:
                time_t getTimeEpoch() const {
                    return timeEpoch;
                }

                const string &getTime() const {
                    return time;
                }

                double getTempC() const {
                    return tempC;
                }

                double getTempF() const {
                    return tempF;
                }

                bool isDay() const {
                    return day;
                }

                const CurrentCondition &getCondition() const {
                    return condition;
                }

                double getWindMph() const {
                    return windMph;
                }

                double getWindKph() const {
                    return windKph;
                }

                int64_t getWindDegree() const {
                    return windDegree;
                }

                const string &getWindDir() const {
                    return windDir;
                }

                int64_t getPressureMb() const {
                    return pressureMb;
                }

                double getPressureIn() const {
                    return pressureIn;
                }

                double getPrecipMm() const {
                    return precipMm;
                }

                double getPrecipIn() const {
                    return precipIn;
                }

                int64_t getHumidity() const {
                    return humidity;
                }

                int64_t getCloud() const {
                    return cloud;
                }

                double getFeelsLikeC() const {
                    return feelsLikeC;
                }

                double getFeelsLikeF() const {
                    return feelsLikeF;
                }

                double getWindChillC() const {
                    return windChillC;
                }

                double getWindChillF() const {
                    return windChillF;
                }

                double getHeatIndexC() const {
                    return heatIndexC;
                }

                double getHeatIndexF() const {
                    return heatIndexF;
                }

                double getDewPointC() const {
                    return dewpointC;
                }

                double getDewPointF() const {
                    return dewPointF;
                }

                bool willItRain() const {
                    return willRain;
                }

                const string &getChanceOfRain() const {
                    return chanceOfRain;
                }

                bool willItSnow() const {
                    return willSnow;
                }

                const string &getChanceOfSnow() const {
                    return chanceOfSnow;
                }

                int64_t getVisKm() const {
                    return visKm;
                }

                int64_t getVisMiles() const {
                    return visMiles;
                }

                double getGustMph() const {
                    return gustMph;
                }

                double getGustKph() const {
                    return gustKph;
                }

            private:
                time_t timeEpoch{};
                std::string time;
                double tempC;
                double tempF;
                bool day;
                CurrentCondition condition;
                double windMph;
                double windKph;
                int64_t windDegree;
                std::string windDir;
                int64_t pressureMb;
                double pressureIn;
                double precipMm;
                double precipIn;
                int64_t humidity;
                int64_t cloud;
                double feelsLikeC;
                double feelsLikeF;
                double windChillC;
                double windChillF;
                double heatIndexC;
                double heatIndexF;
                double dewpointC;
                double dewPointF;
                bool willRain;
                std::string chanceOfRain;
                bool willSnow;
                std::string chanceOfSnow;
                int64_t visKm;
                int64_t visMiles;
                double gustMph;
                double gustKph;

                friend void from_json(const json &j, Hour &h);
            };

            inline void from_json(const json &j, Hour &h) {
                if (j.contains("time_epoch")) {
                    h.timeEpoch = j.at("time_epoch").get<time_t>();
                }

                if (j.contains("time")) {
                    h.time = j.at("time").get<std::string>();
                }

                if (j.contains("temp_c")) {
                    h.tempC = j.at("temp_c").get<double>();
                }

                if (j.contains("temp_f")) {
                    h.tempF = j.at("temp_f").get<double>();
                }

                if (j.contains("is_day")) {
                    h.day = j.at("is_day").get<int>();
                }

                if (j.contains("condition")) {
                    h.condition = j.at("condition").get<CurrentCondition>();
                }

                if (j.contains("wind_mph")) {
                    h.windMph = j.at("wind_mph").get<double>();
                }

                if (j.contains("wind_kph")) {
                    h.windKph = j.at("wind_kph").get<double>();
                }

                if (j.contains("wind_degree")) {
                    h.windDegree = j.at("wind_degree").get<int64_t>();
                }

                if (j.contains("wind_dir")) {
                    h.windDir = j.at("wind_dir").get<std::string>();
                }

                if (j.contains("pressure_mb")) {
                    h.pressureMb = j.at("pressure_mb").get<int64_t>();
                }

                if (j.contains("pressure_in")) {
                    h.pressureIn = j.at("pressure_in").get<double>();
                }

                if (j.contains("precip_mm")) {
                    h.precipMm = j.at("precip_mm").get<double>();
                }

                if (j.contains("precip_in")) {
                    h.precipIn = j.at("precip_in").get<double>();
                }

                if (j.contains("humidity")) {
                    h.humidity = j.at("humidity").get<int64_t>();
                }

                if (j.contains("cloud")) {
                    h.cloud = j.at("cloud").get<int64_t>();
                }

                if (j.contains("feelslike_c")) {
                    h.feelsLikeC = j.at("feelslike_c").get<double>();
                }

                if (j.contains("feelslike_f")) {
                    h.feelsLikeF = j.at("feelslike_f").get<double>();
                }

                if (j.contains("windchill_c")) {
                    h.windChillC = j.at("windchill_c").get<double>();
                }

                if (j.contains("windchill_f")) {
                    h.windChillF = j.at("windchill_f").get<double>();
                }

                if (j.contains("heatindex_c")) {
                    h.heatIndexC = j.at("heatindex_c").get<double>();
                }

                if (j.contains("heatindex_f")) {
                    h.heatIndexF = j.at("heatindex_f").get<double>();
                }

                if (j.contains("dewpoint_c")) {
                    h.dewpointC = j.at("dewpoint_c").get<double>();
                }

                if (j.contains("dewpoint_f")) {
                    h.dewPointF = j.at("dewpoint_f").get<double>();
                }

                if (j.contains("will_it_rain")) {
                    h.willRain = j.at("will_it_rain").get<int>();
                }

                if (j.contains("chance_of_rain")) {
                    h.chanceOfRain = j.at("chance_of_rain").get<std::string>();
                }

                if (j.contains("will_it_snow")) {
                    h.willSnow = j.at("will_it_snow").get<int>();
                }

                if (j.contains("chance_of_snow")) {
                    h.chanceOfSnow = j.at("chance_of_snow").get<std::string>();
                }


                if (j.contains("vis_km")) {
                    h.visKm = j.at("vis_km").get<int64_t>();
                }

                if (j.contains("vis_miles")) {
                    h.visMiles = j.at("vis_miles").get<int64_t>();
                }

                if (j.contains("gust_mph")) {
                    h.gustMph = j.at("gust_mph").get<double>();
                }

                if (j.contains("gust_kph")) {
                    h.gustKph = j.at("gust_kph").get<double>();
                }
            }
        }
    }
}

#endif //APIXU_HOUR_CPP
