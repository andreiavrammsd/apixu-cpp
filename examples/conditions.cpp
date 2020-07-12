// Copyright 2019 <Andrei Avram>
#include <iostream>
#include <vector>

#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"

using std::cout;
using std::endl;
using std::vector;

using Apixu::Exception::ApiException;
using Apixu::Exception::ApixuException;
using Apixu::Response::Condition;

int main()
{
    const char *apiKey = getenv("APIXUKEY");
    if (!apiKey) {
        cout << "APIXUKEY not set";
        return 1;
    }

    auto apixu = new Apixu::Apixu(apiKey);

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
