#include <iostream>
#include <vector>
#include "../src/Apixu.h"
#include "../src/Response/Condition.cpp"
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

    vector<Condition> conditions;
    try {
        conditions = apixu->conditions();
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    for (const auto& c : conditions) {
        cout << "condition" << endl;
        cout << "\tcode: " << c.getCode() << endl;
        cout << "\tday: " << c.getDay() << endl;
        cout << "\tnight: " << c.getNight() << endl;
        cout << "\ticon: " << c.getIcon() << endl << endl;
    }

    delete apixu;

    return 0;
}
