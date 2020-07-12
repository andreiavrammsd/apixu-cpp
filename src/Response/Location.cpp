// Copyright 2019 <Andrei Avram>
#include "Apixu/Response/Location.h"

#include <memory>
#include <string>

namespace Apixu {
namespace Response {
std::shared_ptr<int> Location::getId() const { return id; }

const std::string &Location::getName() const { return name; }

const std::string &Location::getRegion() const { return region; }

const std::string &Location::getCountry() const { return country; }

double Location::getLat() const { return lat; }

double Location::getLon() const { return lon; }

std::shared_ptr<std::string> Location::getUrl() const { return url; }

std::shared_ptr<std::string> Location::getTimezone() const { return timezone; }

std::shared_ptr<int64_t> Location::getLocaltimeEpoch() const
{
    return localtimeEpoch;
}

struct tm Location::getLocaltime() const { return localtime; }
}  // namespace Response
}  // namespace Apixu
