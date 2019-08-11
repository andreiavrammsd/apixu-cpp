#include "Apixu.h"
#include "include/nlohmann/json.hpp"

namespace Apixu {
    Apixu::Apixu(const string &apiKey) : apiKey(apiKey) {}

    vector<Condition> Apixu::conditions() {
        vector<Condition> conditions = json::parse(get(docWeatherConditionsURL));
        return conditions;
    }
}
