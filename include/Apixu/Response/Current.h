// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_CURRENT_H_
#define INCLUDE_APIXU_RESPONSE_CURRENT_H_

#include <string>
#include <memory>

#include "nlohmann/json.hpp"

#include "CurrentCondition.h"
#include "Apixu/Time.h"

namespace Apixu {
    namespace Response {
        class Current {
        public:
            std::shared_ptr<int> getLastUpdatedEpoch() const;

            const tm &getLastUpdated() const;

            std::shared_ptr<float> getTempC() const;

            std::shared_ptr<float> getTempF() const;

            std::shared_ptr<bool> isDay() const;

            const CurrentCondition &getCondition() const;

            std::shared_ptr<float> getWindMph() const;

            std::shared_ptr<float> getWindKph() const;

            std::shared_ptr<int> getWindDegree() const;

            std::shared_ptr<std::string> getWindDir() const;

            std::shared_ptr<float> getPressureMb() const;

            std::shared_ptr<float> getPressureIn() const;

            std::shared_ptr<float> getPrecipMm() const;

            std::shared_ptr<float> getPrecipIn() const;

            std::shared_ptr<int> getHumidity() const;

            std::shared_ptr<int> getCloud() const;

            std::shared_ptr<float> getFeelslikeC() const;

            std::shared_ptr<float> getFeelslikeF() const;

            std::shared_ptr<float> getVisKm() const;

            std::shared_ptr<float> getVisMiles() const;

            std::shared_ptr<float> getUv() const;

            std::shared_ptr<float> getGustMph() const;

            std::shared_ptr<float> getGustKph() const;

            virtual ~Current() = default;

        private:
            std::shared_ptr<int> lastUpdatedEpoch{};
            struct tm lastUpdated{};
            std::shared_ptr<float> tempC{};
            std::shared_ptr<float> tempF{};
            std::shared_ptr<bool>day{};
            CurrentCondition condition;
            std::shared_ptr<float> windMph{};
            std::shared_ptr<float> windKph{};
            std::shared_ptr<int> windDegree{};
            std::shared_ptr<std::string>windDir{};
            std::shared_ptr<float> pressureMb{};
            std::shared_ptr<float> pressureIn{};
            std::shared_ptr<float> precipMm{};
            std::shared_ptr<float> precipIn{};
            std::shared_ptr<int> humidity{};
            std::shared_ptr<int> cloud{};
            std::shared_ptr<float> feelslikeC{};
            std::shared_ptr<float> feelslikeF{};
            std::shared_ptr<float> visKm{};
            std::shared_ptr<float> visMiles{};
            std::shared_ptr<float> uv{};
            std::shared_ptr<float> gustMph{};
            std::shared_ptr<float> gustKph{};

            friend void from_json(const nlohmann::json &j, Current &c); // NOLINT
        };

        inline void from_json(const nlohmann::json &j, Current &c) { // NOLINT
            if (j.contains("last_updated_epoch")) {
                c.lastUpdatedEpoch = std::make_shared<int>(j.at("last_updated_epoch"));
            }

            if (j.contains("last_updated")) {
                c.lastUpdated = Time::parse(j.at("last_updated"));
            }

            if (j.contains("temp_c")) {
                c.tempC = std::make_shared<float>(j.at("temp_c"));
            }

            if (j.contains("temp_f")) {
                c.tempF = std::make_shared<float>(j.at("temp_f"));
            }

            if (j.contains("is_day")) {
                c.day = std::make_shared<bool>(j.at("is_day").get<int>());
            }

            c.condition = j.at("condition");

            if (j.contains("wind_mph")) {
                c.windMph = std::make_shared<float>(j.at("wind_mph"));
            }

            if (j.contains("wind_kph")) {
                c.windKph = std::make_shared<float>(j.at("wind_kph"));
            }

            if (j.contains("wind_degree")) {
                c.windDegree = std::make_shared<int>(j.at("wind_degree"));
            }

            if (j.contains("wind_dir")) {
                c.windDir = std::make_shared<std::string>(j.at("wind_dir"));
            }

            if (j.contains("pressure_mb")) {
                c.pressureMb = std::make_shared<float>(j.at("pressure_mb"));
            }

            if (j.contains("pressure_in")) {
                c.pressureIn = std::make_shared<float>(j.at("pressure_in"));
            }

            if (j.contains("precip_mm")) {
                c.precipMm = std::make_shared<float>(j.at("precip_mm"));
            }

            if (j.contains("precip_in")) {
                c.precipIn = std::make_shared<float>(j.at("precip_in"));
            }

            if (j.contains("humidity")) {
                c.humidity = std::make_shared<int>(j.at("humidity"));
            }

            if (j.contains("cloud")) {
                c.cloud = std::make_shared<int>(j.at("cloud"));
            }

            if (j.contains("feelslike_c")) {
                c.feelslikeC = std::make_shared<float>(j.at("feelslike_c"));
            }

            if (j.contains("feelslike_f")) {
                c.feelslikeF = std::make_shared<float>(j.at("feelslike_f"));
            }

            if (j.contains("vis_km")) {
                c.visKm = std::make_shared<float>(j.at("vis_km"));
            }

            if (j.contains("vis_miles")) {
                c.visMiles = std::make_shared<float>(j.at("vis_miles"));
            }

            if (j.contains("uv")) {
                c.uv = std::make_shared<float>(j.at("uv"));
            }

            if (j.contains("gust_mph")) {
                c.gustMph = std::make_shared<float>(j.at("gust_mph"));
            }

            if (j.contains("gust_kph")) {
                c.gustKph = std::make_shared<float>(j.at("gust_kph"));
            }
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_CURRENT_H_
