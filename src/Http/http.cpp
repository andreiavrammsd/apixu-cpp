// Copyright 2020 <Andrei Avram>
#include "Apixu/Http/http.h"

#include <curl/curl.h>

#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "exception.cpp"

namespace apixu {
namespace http {
Client::Client(std::string userAgent) : userAgent(std::move(userAgent)) {}

inline std::string paramsToQuery(CURL* curl,
                                 std::map<std::string, std::string> params)
{
    std::ostringstream query;

    for (auto iter = params.begin(); iter != params.end();) {
        char* key =
            curl_easy_escape(curl, iter->first.c_str(), iter->first.length());
        char* value =
            curl_easy_escape(curl, iter->second.c_str(), iter->second.length());
        if (!key || !value) {
            throw Exception("Cannot escape query params");
        }

        query << key << "=" << value;
        curl_free(key);
        curl_free(value);

        if (next(iter) != params.end()) {
            query << "&";
        }
        ++iter;
    }

    return query.str();
}

inline size_t writeCallback(void* contents, size_t size, size_t nmemb,
                            void* userp)
{
    (static_cast<std::string*>(userp))
        ->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

const Response* Client::get(const std::string& url)
{
    std::map<std::string, std::string> params;
    return get(url, params);
}

const Response* Client::get(const std::string& url,
                            std::map<std::string, std::string> params)
{
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw Exception("Cannot init curl");
    }

    std::string api_url = url + "?" + paramsToQuery(curl, params);

    curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
    curl_easy_setopt(curl, CURLOPT_USERAGENT, userAgent.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

    std::string read_buffer;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        throw Exception(curl_easy_strerror(res));
    }

    int responseCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);

    curl_easy_cleanup(curl);

    return new Response(responseCode, read_buffer);
}

int Response::getStatus() const { return status_; }

const std::string& Response::getBody() const { return body_; }

Response::Response(int status, std::string body)
    : status_(status), body_(std::move(body))
{
}
}  // namespace http
}  // namespace apixu
