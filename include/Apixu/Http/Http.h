// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_HTTP_HTTP_H_
#define INCLUDE_APIXU_HTTP_HTTP_H_


#include <map>
#include <string>

namespace Apixu {
    namespace Http {
        using std::string;
        using std::map;

        const int STATUS_INTERNAL_SERVER_ERROR = 500;
        const int STATUS_BAD_REQUEST = 400;

        class Response {
        public:
            Response(int status, string body);

            virtual int getStatus() const;

            virtual const string &getBody() const;

            virtual ~Response() = default;

        private:
            int status;
            string body;
        };

        class Http {
        public:
            virtual const Response *get(const string &path, map<string, string> params) = 0;

            virtual const Response *get(const string &path) = 0;

            virtual ~Http() = default;
        };

        class Client : public Http {
        public:
            explicit Client(string userAgent);

            const Response *get(const string &url, map<string, string> params) override;

            const Response *get(const string &url) override;

        private:
            string userAgent;
        };
    }  // namespace Http
}  // namespace Apixu

#endif  // INCLUDE_APIXU_HTTP_HTTP_H_
