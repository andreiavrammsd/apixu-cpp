#include <iostream>
#include <vector>
#include "Apixu.h"
#include "Condition.h"
#include "Location.h"

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (apiKey == nullptr) {
        throw "APIXUKEY not set";
    }

    auto apixu = new Apixu::Apixu(apiKey);

//    vector<Apixu::Condition> conditions = apixu->conditions();
//
//    for (const auto& c : conditions) {
//        cout << "condition" << endl;
//        cout << "\tcode: " << c.getCode() << endl;
//        cout << "\tday: " << c.getDay() << endl;
//        cout << "\tnight: " << c.getNight() << endl;
//        cout << "\ticon: " << c.getIcon() << endl << endl;
//    }

    Apixu::CurrentWeather currentWeather = apixu->current("zalau");

    cout << "location" << endl;

    const Apixu::Location& location = currentWeather.getLocation();

    if (location.getId() != nullptr) {
        cout << "\tid = " << *location.getId() << endl;
    }
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

    const Apixu::Current& current = currentWeather.getCurrent();

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

    return 0;
}
