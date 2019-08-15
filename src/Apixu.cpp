#include <sstream>
#include "Apixu.h"
#include "Exception/ApiException.cpp"
#include "Response/Error.cpp"

using namespace Apixu::Exception;
using namespace std;

namespace Apixu {
    Apixu::Apixu(string apiKey) : apiKey(move(apiKey)) {
        httpClient = new HTTP::Client(USER_AGENT);
    }

    Apixu::~Apixu() {
        delete httpClient;
    }

    vector<Condition> Apixu::conditions() {
        try {
            return json::parse(get(DOC_WEATHER_CONDITIONS_URL, nullptr));
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    CurrentWeather Apixu::current(const string& q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("current"), &params));
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    vector<Location> Apixu::search(const string &q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;

        try {
            return json::parse(get(url("search"), &params));
        } catch (exception &e) {
            throw ApixuException(e.what());
        }
    }

    string Apixu::url(const string& method) {
        return API_URL + method + "." + API_FORMAT;
    }

    string Apixu::get(const string &url, const map<string, string>* params) {
        auto response = httpClient->get(url, params);
        int status = response->getStatus();
        string body = response->getBody();
        delete response;

        if (status >= STATUS_INTERNAL_SERVER_ERROR) {
            throw ApixuException("Internal Server Error");
        } else if (status >= STATUS_BAD_REQUEST) {
            ErrorResponse errRes = json::parse(body);
            throw ApiException(errRes.getError().getMessage(), errRes.getError().getCode());
        }

        return body;
    }
}
