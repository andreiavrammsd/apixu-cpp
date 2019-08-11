#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "include/nlohmann/json.hpp"
#include "Apixu.cpp"
#include "Condition.h"

int main() {
    char* apiKey = getenv("APIXUKEY");
    if (apiKey == nullptr) {
        throw "APIXUKEY not set";
    }

    const string k = string(apiKey);
    auto apixu = new Apixu(k);
    vector<Condition> conditions = apixu->conditions();

    for (const auto& c : conditions) {
        cout << "condition" << endl;
        cout << "\tcode: " << c.getCode() << endl;
        cout << "\tday: " << c.getDay() << endl;
        cout << "\tnight: " << c.getNight() << endl;
        cout << "\ticon: " << c.getIcon() << endl << endl;
    }

    return 0;
}
