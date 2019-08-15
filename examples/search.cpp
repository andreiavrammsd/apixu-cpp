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

    vector<Location> locations = apixu->search("hida, salaj");

    for (const auto& loc : locations) {
        cout << "id = " << *loc.getId() << endl;
        cout << "name = " << loc.getName() << endl;
        cout << "region = " << loc.getRegion() << endl;
        cout << "country = " << loc.getCountry() << endl;
        cout << "lat = " << loc.getLat() << endl;
        cout << "lon = " << loc.getLon() << endl;
        if (loc.getUrl()) {
            cout << "url = " << *loc.getUrl() << endl;
        }
        cout << endl;
    }

    delete apixu;

    return 0;
}
