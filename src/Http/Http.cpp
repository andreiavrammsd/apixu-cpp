#include "Http.hpp"
#include <curl/curl.h>
#include <sstream>
#include <utility>
#include "Exception.cpp"

namespace Apixu {
    namespace Http {
        using std::ostringstream;
        Client::Client(string userAgent) : userAgent(std::move(userAgent)) {}

        inline string paramsToQuery(CURL* curl, const map<string, string> *params) {
            ostringstream query;

            for (auto iter = params->begin(); iter != params->end();) {
                char *key = curl_easy_escape(curl, iter->first.c_str(), iter->first.length());
                char *value = curl_easy_escape(curl, iter->second.c_str(), iter->second.length());
                if (!key || !value) {
                    throw Exception("Cannot escape query params");
                }

                query << key << "=" << value;
                curl_free(key);
                curl_free(value);

                if (next(iter) != params->end()) {
                    query << "&";
                }
                ++iter;
            }

            return query.str();
        }

        inline size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
            ((std::string *) userp)->append((char *) contents, size * nmemb);
            return size * nmemb;
        }

        const Response *Client::get(const string& url, const map<string, string> *params) {
            CURL* curl = curl_easy_init();
            if (!curl) {
                throw Exception("Cannot init curl");
            }

            string apiUrl = url;
            if (params) {
                apiUrl += "?" + paramsToQuery(curl, params);
            }

            curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
            curl_easy_setopt(curl, CURLOPT_USERAGENT, userAgent.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

            string readBuffer;
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                throw Exception(curl_easy_strerror(res));
            }

            int responseCode;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);

            curl_easy_cleanup(curl);

            return new Response(responseCode, readBuffer);
        }

        int Response::getStatus() const {
            return status;
        }

        const string &Response::getBody() const {
            return body;
        }

        Response::Response(int status, string body) : status(status), body(std::move(body)) {}
    }
}
