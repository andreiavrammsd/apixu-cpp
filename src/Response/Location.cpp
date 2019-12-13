// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Location.h"

#include <string>
#include <memory>

namespace Apixu {
    namespace Response {
        std::shared_ptr<int> Location::getId() const {
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

        std::shared_ptr<string> Location::getUrl() const {
            return url;
        }

        std::shared_ptr<string> Location::getTimezone() const {
            return timezone;
        }

        std::shared_ptr<int64_t> Location::getLocaltimeEpoch() const {
            return localtimeEpoch;
        }

        struct tm Location::getLocaltime() const {
            return localtime;
        }
    }  // namespace Response
}  // namespace Apixu
