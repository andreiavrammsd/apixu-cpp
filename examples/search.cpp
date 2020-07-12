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
    const char *api_key = getenv("APIXUKEY");
    if (!api_key) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(api_key);

    vector<Location> locations = apixu->Search("Koln, Germany");

    for (const auto &loc : locations) {
        if (loc.id) {
            cout << "id = " << *loc.id << endl;
        }
        cout << "name = " << loc.name << endl;
        cout << "region = " << loc.region << endl;
        cout << "country = " << loc.country << endl;
        cout << "lat = " << loc.lat << endl;
        cout << "lon = " << loc.lon << endl;
        cout << "url = " << *loc.url << endl;
        cout << "timezone = " << *loc.timezone << endl;
        cout << "localtime epoch = " << *loc.localtime_epoch << endl;
        cout << "localtime = " << loc.localtime.tm_min << endl;
        cout << endl;
    }

    delete apixu;

    return 0;
}
