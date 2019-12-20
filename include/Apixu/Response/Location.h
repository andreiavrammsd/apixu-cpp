// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_LOCATION_H_
#define INCLUDE_APIXU_RESPONSE_LOCATION_H_


#include <memory>
#include <string>

#include "nlohmann/json.hpp"
#include "Apixu/Time.h"

namespace Apixu {
    namespace Response {
        class Location {
        public:
            std::shared_ptr<int> getId() const;

            const std::string &getName() const;

            const std::string &getRegion() const;

            const std::string &getCountry() const;

            double getLat() const;

            double getLon() const;

            std::shared_ptr<std::string> getUrl() const;

            std::shared_ptr<std::string> getTimezone() const;

            std::shared_ptr<int64_t> getLocaltimeEpoch() const;

            struct tm getLocaltime() const;

            virtual ~Location() = default;

        private:
            std::shared_ptr<int> id;
            std::string name;
            std::string region;
            std::string country;
            double lat{};
            double lon{};
            std::shared_ptr<std::string> url{};
            std::shared_ptr<std::string> timezone{};
            std::shared_ptr<int64_t> localtimeEpoch{};
            struct tm localtime{};

            friend void from_json(const nlohmann::json &j, Location &l); // NOLINT
        };

        inline void from_json(const nlohmann::json &j, Location &l) { // NOLINT
            if (j.contains("id")) {
                l.id = std::make_shared<int>(j.at("id"));
            }

            l.name = j.at("name");
            l.region = j.at("region");
            l.country = j.at("country");
            l.lat = j.at("lat");
            l.lon = j.at("lon");

            if (j.contains("url")) {
                l.url = std::make_shared<std::string>(j.at("url"));
            }

            if (j.contains("tz_id")) {
                l.timezone = std::make_shared<std::string>(j.at("tz_id"));
            }

            if (j.contains("localtime_epoch")) {
                l.localtimeEpoch = std::make_shared<int64_t>(j.at("localtime_epoch"));
            }

            if (j.contains("localtime")) {
                l.localtime = Time::parse(j.at("localtime"));
            }
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_LOCATION_H_
