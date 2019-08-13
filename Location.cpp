#include "Location.h"

namespace Apixu {
    const int *Location::getId() const {
        return id;
    }

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

    const string *Location::getUrl() const {
        return url;
    }

    const string* Location::getTimezone() const {
        return timezone;
    }

    int64_t* Location::getLocaltimeEpoch() const {
        return localtimeEpoch;
    }

    struct tm Location::getLocaltime() const {
        return localtime;
    }

    Location::~Location() {
//        delete id;
//        delete url;
//        delete timezone;
//        delete localtimeEpoch;
//        delete localtime;
    }
}
