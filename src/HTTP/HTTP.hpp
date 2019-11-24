#ifndef APIXU_HTTP_HTTP_HPP_
#define APIXU_HTTP_HTTP_HPP_


#include <map>

namespace Apixu {
    namespace HTTP {
        using std::string;
        using std::map;

        const int STATUS_INTERNAL_SERVER_ERROR = 500;
        const int STATUS_BAD_REQUEST = 400;

        class Response {
        public:
            Response(int status, string body);

            int getStatus() const;

            const string &getBody() const;

            virtual ~Response() = default;

        private:
            int status;
            string body;
        };

        class HTTP {
        public:
            virtual const Response *get(const string& path, const map<string, string>* params) = 0;
            virtual ~HTTP() = default;
        };

        class Client : public HTTP {
        public:
            explicit Client(string userAgent);

            const Response *get(const string& url, const map<string, string>* params) override;

        private:
            string userAgent;
        };
    }
}

#endif // APIXU_HTTP_HTTP_HPP_
