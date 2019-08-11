#include "Location.h"

namespace Apixu {
    const string &Location::getName() const {
        return name;
    }

    const string &Location::getRegion() const {
        return region;
    }

    const string &Location::getCountry() const {
        return country;
    }

    double Location::getLat() const {
        return lat;
    }

    double Location::getLon() const {
        return lon;
    }

    const string &Location::getTzId() const {
        return tzId;
    }

    int64_t Location::getLocaltimeEpoch() const {
        return localtimeEpoch;
    }

    const string &Location::getLocaltime() const {
        return localtime;
    }
}
