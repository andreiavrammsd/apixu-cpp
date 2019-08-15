#include <sstream>
#include <iostream>
#include "Apixu.h"
#include "include/nlohmann/json.hpp"
#include "Exception/ApiException.cpp"
#include "Exception/FatalErrorException.cpp"
#include "Response/Error.cpp"

using namespace Apixu::Exception;
using namespace std;

namespace Apixu {
    Apixu::Apixu(string apiKey) : apiKey(move(apiKey)) {}

    vector<Condition> Apixu::conditions() {
        return json::parse(get(DOC_WEATHER_CONDITIONS_URL, nullptr));
    }

    CurrentWeather Apixu::current(const string& q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        return json::parse(get(url("current"), &params));
    }

    vector<Location> Apixu::search(const string &q) {
        map<string, string> params;
        params["key"] = apiKey;
        params["q"] = q;
        return json::parse(get(url("search"), &params));
    }

    string Apixu::url(const string& method) {
        return API_URL + method + "." + API_FORMAT;
    }

    string Apixu::get(const string &url, const map<string, string>* params) {
        CURL* curl = curl_easy_init();
        if (!curl) {
            throw FatalErrorException("Cannot init curl");
        }

        ostringstream query;
        if (params) {
            for (auto iter = params->begin(); iter != params->end();) {
                char *key = curl_easy_escape(curl, iter->first.c_str(), iter->first.length());
                char *value = curl_easy_escape(curl, iter->second.c_str(), iter->second.length());
                if (!key || !value) {
                    throw "valeu";
                }

                query << key << "=" << value;
                curl_free(key);
                curl_free(value);

                if (next(iter) != params->end()) {
                    query << "&";
                }
                ++iter;
            }
        }

        curl_easy_setopt(curl, CURLOPT_URL, (url + "?" + query.str()).c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

        string readBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            throw FatalErrorException(curl_easy_strerror(res));
        }

        int responseCode;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);

        curl_easy_cleanup(curl);

        if (responseCode >= 500) {
            throw FatalErrorException("Internal Server Error");
        } else if (responseCode >= 400) {
            ErrorResponse errRes;
            try {
                errRes = json::parse(readBuffer);
            } catch (json::parse_error &e) {
                throw FatalErrorException(e.what());
            }

            throw ApiException(errRes.getError().getCode(), errRes.getError().getMessage());
        }

        return readBuffer;
    }

    size_t Apixu::writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string *) userp)->append((char *) contents, size * nmemb);
        return size * nmemb;
    }
}
