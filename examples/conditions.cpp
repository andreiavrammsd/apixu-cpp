#include <iostream>
#include <vector>
#include "../src/Apixu.hpp"
#include "../src/Response/Condition.hpp"
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
