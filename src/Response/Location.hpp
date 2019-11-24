#ifndef APIXU_RESPONSE_LOCATION_HPP_
#define APIXU_RESPONSE_LOCATION_HPP_


#include <string>
#include "nlohmann/json.hpp"
#include "../Time.hpp"

namespace Apixu {
    using std::string;
    using nlohmann::json;

    namespace Response {
        class Location {
        public:
            const int *getId() const;

            const string &getName() const;

            const string &getRegion() const;

            const string &getCountry() const;

            double getLat() const;

            double getLon() const;

            const string *getUrl() const;

            const string *getTimezone() const;

            int64_t *getLocaltimeEpoch() const;

            struct tm getLocaltime() const;

            virtual ~Location() = default;

        private:
            int *id{};
            string name;
            string region;
            string country;
            double lat{};
            double lon{};
            string *url{};
            string *timezone{};
            int64_t *localtimeEpoch{};
            struct tm localtime{};

            friend void from_json(const json &j, Location &l);
        };

        inline void from_json(const json &j, Location &l) {
            if (j.contains("id")) {
                l.id = new int(j.at("id").get<int>());
            }

            l.name = j.at("name").get<string>();
            l.region = j.at("region").get<string>();
            l.country = j.at("country").get<string>();
            l.lat = j.at("lat").get<double>();
            l.lon = j.at("lon").get<double>();

            if (j.contains("url")) {
                l.url = new string(j.at("url").get<string>());
            }

            if (j.contains("tz_id")) {
                l.timezone = new string(j.at("tz_id").get<string>());
            }

            if (j.contains("localtime_epoch")) {
                l.localtimeEpoch = new int64_t(j.at("localtime_epoch").get<int64_t>());
            }

            if (j.contains("localtime")) {
                l.localtime = Time::parse(j.at("localtime").get<string>());
            }
        }
    }
}

#endif // APIXU_RESPONSE_LOCATION_HPP_
