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

    CurrentWeather currentWeather;
    try {
        currentWeather = apixu->current("zalau");
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    cout << "location" << endl;

    const Location& location = currentWeather.getLocation();

    cout << "\tname = " << location.getName() << endl;
    cout << "\tregion = " << location.getRegion() << endl;
    cout << "\tcountry = " << location.getCountry() << endl;
    cout << "\tlat = " << location.getLat() << endl;
    cout << "\tlon = " << location.getLon() << endl;
    if (location.getUrl() != nullptr) {
        cout << "\turl = " << *location.getUrl() << endl;
    }
    if (location.getTimezone() != nullptr) {
        cout << "\ttimezone = " << *location.getTimezone() << endl;
    }
    if (location.getLocaltimeEpoch() != nullptr) {
        cout << "\tlocaltime epoch = " << *location.getLocaltimeEpoch() << endl;
    }

    auto localtime = location.getLocaltime();
    cout << "\tlocaltime = " << localtime.tm_year << localtime.tm_hour << endl;

    cout << "current weather" << endl;

    const Current& current = currentWeather.getCurrent();

    if (current.getLastUpdatedEpoch()) {
        cout << "\tlast updated epoch " << *current.getLastUpdatedEpoch() << endl;
    }

    cout << "\tlast updated " << current.getLastUpdated().tm_year << endl;

    if (current.getTempC()) {
        cout << "\ttemp C " << *current.getTempC() << endl;
    }

    if (current.getTempF()) {
        cout << "\ttemp F " << *current.getTempF() << endl;
    }

    cout << "\tcondition " << endl;
    cout << "\t\ttext " << *current.getCondition().getText() << endl;
    cout << "\t\ticon " << *current.getCondition().getIcon() << endl;
    cout << "\t\tcode " << *current.getCondition().getCode() << endl;

    delete apixu;

    return 0;
}
