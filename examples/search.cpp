#include <iostream>
#include <vector>
#include "../src/Apixu.hpp"
#include "../src/Exception/ApiException.cpp"

using namespace Apixu::Exception;
using namespace Apixu::Response;
using std::cout;
using std::endl;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    vector<Location> locations = apixu->search("Koln, Germany");

    for (const auto& loc : locations) {
        cout << "id = " << *loc.getId() << endl;
        cout << "name = " << loc.getName() << endl;
        cout << "region = " << loc.getRegion() << endl;
        cout << "country = " << loc.getCountry() << endl;
        cout << "lat = " << loc.getLat() << endl;
        cout << "lon = " << loc.getLon() << endl;
        cout << "url = " << *loc.getUrl() << endl;
        cout << endl;
    }

    delete apixu;

    return 0;
}
