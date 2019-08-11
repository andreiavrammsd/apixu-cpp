#include <iostream>
#include <vector>
#include "Apixu.h"
#include "Condition.h"

int main() {
    char* apiKey = getenv("APIXUKEY");
    if (apiKey == nullptr) {
        throw "APIXUKEY not set";
    }

    const string k = string(apiKey);
    auto apixu = new Apixu::Apixu(k);

    vector<Apixu::Condition> conditions = apixu->conditions();

    for (const auto& c : conditions) {
        cout << "condition" << endl;
        cout << "\tcode: " << c.getCode() << endl;
        cout << "\tday: " << c.getDay() << endl;
        cout << "\tnight: " << c.getNight() << endl;
        cout << "\ticon: " << c.getIcon() << endl << endl;
    }

    Apixu::CurrentWeather currentWeather = apixu->current("zalau");
    cout << "location" << endl;
    cout << "\tname = " << currentWeather.getLocation().getName() << endl;
    cout << "\tregion = " << currentWeather.getLocation().getRegion() << endl;
    cout << "\tcountry = " << currentWeather.getLocation().getCountry() << endl;

    return 0;
}
