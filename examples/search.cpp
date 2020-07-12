// Copyright 2019 <Andrei Avram>
#include <iostream>
#include <vector>

#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"

using std::cout;
using std::endl;
using std::vector;

using Apixu::Exception::ApiException;
using Apixu::Exception::ApixuException;
using Apixu::Response::Location;

int main()
{
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    vector<Location> locations = apixu->Search("Koln, Germany");

    for (const auto &loc : locations) {
        if (loc.getId()) {
            cout << "id = " << *loc.getId() << endl;
        }
        cout << "name = " << loc.getName() << endl;
        cout << "region = " << loc.getRegion() << endl;
        cout << "country = " << loc.getCountry() << endl;
        cout << "lat = " << loc.getLat() << endl;
        cout << "lon = " << loc.getLon() << endl;
        cout << "url = " << *loc.getUrl() << endl;
        cout << "timezone = " << *loc.getTimezone() << endl;
        cout << "localtime epoch = " << *loc.getLocaltimeEpoch() << endl;
        cout << "localtime = " << loc.getLocaltime().tm_min << endl;
        cout << endl;
    }

    delete apixu;

    return 0;
}
