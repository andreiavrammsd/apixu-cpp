// Copyright 2019 <Andrei Avram>
#include <iostream>
#include <vector>

#include "Apixu/Exception/api_exception.h"
#include "Apixu/apixu.h"

using std::cout;
using std::endl;
using std::vector;

using apixu::exception::ApiException;
using apixu::exception::ApixuException;
using apixu::response::Condition;

int main()
{
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new apixu::Apixu(apiKey);

    vector<Condition> conditions;
    try {
        conditions = apixu->Conditions();
    }
    catch (ApiException &e) {
        cout << "ApiException: " << e.what() << " (code: " << e.getCode()
             << ")";
        return 1;
    }
    catch (ApixuException &e) {
        cout << "ApixuException: " << e.what();
        return 1;
    }

    for (const auto &c : conditions) {
        cout << "code: " << c.code << endl;
        cout << "day: " << c.day << endl;
        cout << "night: " << c.night << endl;
        cout << "icon: " << c.icon << endl << endl;
    }

    delete apixu;

    return 0;
}
