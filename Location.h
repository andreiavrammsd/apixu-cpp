#ifndef APIXU_DEV_LOCATION_H
#define APIXU_DEV_LOCATION_H

#include <string>
#include "include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    class Location {
    public:
        Location() = default;
        virtual ~Location() = default;

        const string &getName() const;

        const string &getRegion() const;

        const string &getCountry() const;

        double getLat() const;

        double getLon() const;

        const string &getTzId() const;

        int64_t getLocaltimeEpoch() const;

        const string &getLocaltime() const;

    private:
        string name;
        string region;
        string country;
        double lat{};
        double lon{};
        string tzId;
        int64_t localtimeEpoch{};
        string localtime;
        friend void from_json(const json & j, Location& l);
    };

    inline void from_json(const json & j, Location& l) {
        l.name = j.at("name").get<std::string>();
        l.region = j.at("region").get<std::string>();
        l.country = j.at("country").get<std::string>();
        l.lat = j.at("lat").get<double>();
        l.lon = j.at("lon").get<double>();
        l.tzId = j.at("tz_id").get<std::string>();
        l.localtimeEpoch = j.at("localtime_epoch").get<int64_t>();
        l.localtime = j.at("localtime").get<std::string>();
    }
}

#endif //APIXU_DEV_LOCATION_H
