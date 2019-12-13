// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_ERROR_H_
#define INCLUDE_APIXU_RESPONSE_ERROR_H_


#include <string>
#include "nlohmann/json.hpp"

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
            int code{};
            string message;

            friend void from_json(const json &j, Error &e); // NOLINT
        };

        inline void from_json(const json &j, Error &e) { // NOLINT
            e.code = j.at("code");
            e.message = j.at("message");
        }

        class ErrorResponse {
        public:
            const Error &getError() const;

        private:
            friend void from_json(const json &j, ErrorResponse &e); // NOLINT

            Error error;
        };

        inline void from_json(const json &j, ErrorResponse &e) { // NOLINT
            e.error = j.at("error");
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_ERROR_H_
