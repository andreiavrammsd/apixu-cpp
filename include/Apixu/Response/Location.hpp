#ifndef APIXU_RESPONSE_LOCATION_HPP_
#define APIXU_RESPONSE_LOCATION_HPP_


#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "Apixu/Time.hpp"

namespace Apixu {
    using std::string;
    using nlohmann::json;

    namespace Response {
        class Location {
        public:
            std::shared_ptr<int> getId() const;

            const string &getName() const;

            const string &getRegion() const;

            const string &getCountry() const;

            double getLat() const;

            double getLon() const;

            std::shared_ptr<string> getUrl() const;

            std::shared_ptr<string> getTimezone() const;

            std::shared_ptr<int64_t> getLocaltimeEpoch() const;

            struct tm getLocaltime() const;

            virtual ~Location() = default;

        private:
            std::shared_ptr<int> id;
            string name;
            string region;
            string country;
            double lat{};
            double lon{};
            std::shared_ptr<string> url{};
            std::shared_ptr<string> timezone{};
            std::shared_ptr<int64_t> localtimeEpoch{};
            struct tm localtime{};

            friend void from_json(const json &j, Location &l);
        };

        inline void from_json(const json &j, Location &l) {
            if (j.contains("id")) {
                l.id = std::make_shared<int>(j.at("id"));
            }

            l.name = j.at("name");
            l.region = j.at("region");
            l.country = j.at("country");
            l.lat = j.at("lat");
            l.lon = j.at("lon");

            if (j.contains("url")) {
                l.url = std::make_shared<string>(j.at("url"));
            }

            if (j.contains("tz_id")) {
                l.timezone = std::make_shared<string>(j.at("tz_id"));
            }

            if (j.contains("localtime_epoch")) {
                l.localtimeEpoch = std::make_shared<int64_t>(j.at("localtime_epoch"));
            }

            if (j.contains("localtime")) {
                l.localtime = Time::parse(j.at("localtime"));
            }
        }
    }
}

#endif // APIXU_RESPONSE_LOCATION_HPP_
