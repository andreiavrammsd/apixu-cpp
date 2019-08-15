#ifndef APIXU_LOCATION_CPP
#define APIXU_LOCATION_CPP

#include <string>
#include "../../include/nlohmann/json.hpp"
#include "../Time.h"

using namespace std;
using nlohmann::json;

namespace Apixu {
    namespace Response {
        class Location {
        public:
            Location() = default;

            const int *getId() const {
                return id;
            }

            const string &getName() const {
                return name;
            }

            const string &getRegion() const {
                return region;
            }

            const string &getCountry() const {
                return country;
            }

            double getLat() const {
                return lat;
            }

            double getLon() const {
                return lon;
            }

            const string *getUrl() const {
                return url;
            }

            const string *getTimezone() const {
                return timezone;
            }

            int64_t *getLocaltimeEpoch() const {
                return localtimeEpoch;
            }

            struct tm getLocaltime() const {
                return localtime;
            }

            ~Location() {
//        delete id;
//        delete url;
//        delete timezone;
//        delete localtimeEpoch;
//        delete localtime;
            }

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

#endif //APIXU_LOCATION_CPP
