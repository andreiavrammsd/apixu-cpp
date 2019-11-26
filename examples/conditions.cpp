#include <iostream>
#include <vector>
#include "Apixu/Apixu.hpp"
#include "Apixu/Exception/ApiException.hpp"

using Apixu::Exception::ApiException;
using Apixu::Exception::ApixuException;
using std::cout;
using std::endl;

int main() {
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

    vector<Condition> conditions;
    try {
        conditions = apixu->Conditions();
    } catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode() << ")";
        return 1;
    } catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    for (const auto& c : conditions) {
        cout << "code: " << c.getCode() << endl;
        cout << "day: " << c.getDay() << endl;
        cout << "night: " << c.getNight() << endl;
        cout << "icon: " << c.getIcon() << endl << endl;
    }

    delete apixu;

    return 0;
}
