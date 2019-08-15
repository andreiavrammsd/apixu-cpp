#include <iostream>
#include <vector>
#include "../src/Apixu.h"
#include "../src/Response/Location.cpp"
#include "../src/Exception/ApiException.cpp"

using namespace Apixu::Exception;
using namespace Apixu::Response;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (apiKey == nullptr) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    vector<Location> locations = apixu->search("Turbuta, Salaj, Romania");

    for (const auto& loc : locations) {
        cout << "\tid = " << *loc.getId() << endl;
        cout << "\tname = " << loc.getName() << endl;
        cout << "\tregion = " << loc.getRegion() << endl;
        cout << "\tcountry = " << loc.getCountry() << endl;
        cout << "\tlat = " << loc.getLat() << endl;
        cout << "\tlon = " << loc.getLon() << endl;
        if (loc.getUrl() != nullptr) {
            cout << "\turl = " << *loc.getUrl() << endl;
        }
        if (loc.getTimezone() != nullptr) {
            cout << "\ttimezone = " << *loc.getTimezone() << endl;
        }
        if (loc.getLocaltimeEpoch() != nullptr) {
            cout << "\tlocaltime epoch = " << *loc.getLocaltimeEpoch() << endl;
        }

        auto localt = loc.getLocaltime();
        cout << "\tlocaltime = " << localt.tm_year << localt.tm_hour << endl << endl;
    }

    delete apixu;

    return 0;
}
