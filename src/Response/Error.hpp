#ifndef APIXU_RESPONSE_ERROR_HPP_
#define APIXU_RESPONSE_ERROR_HPP_


#include <string>
#include <nlohmann/json.hpp>

namespace Apixu {
    namespace Response {
        using std::string;
        using nlohmann::json;

        class Error {
        public:
            int getCode() const;

            const string &getMessage() const;

            virtual ~Error() = default;

        private:
            int code;
            string message;

            friend void from_json(const json &j, Error &e);
        };

        inline void from_json(const json &j, Error &e) {
            e.code = j.at("code").get<int>();
            e.message = j.at("message").get<string>();
        }

        class ErrorResponse {
        public:
            const Error &getError() const;

        private:
            friend void from_json(const json &j, ErrorResponse &e);

            Error error;
        };

        inline void from_json(const json &j, ErrorResponse &e) {
            e.error = j.at("error").get<Error>();
        }
    }
}

#endif // APIXU_RESPONSE_ERROR_HPP_
