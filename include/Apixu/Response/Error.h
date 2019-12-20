// Copyright 2019 <Andrei Avram>
#ifndef INCLUDE_APIXU_RESPONSE_ERROR_H_
#define INCLUDE_APIXU_RESPONSE_ERROR_H_


#include <string>

#include "nlohmann/json.hpp"

namespace Apixu {
    namespace Response {
        class Error {
        public:
            int getCode() const;

            const std::string &getMessage() const;

            virtual ~Error() = default;

        private:
            int code{};
            std::string message;

            friend void from_json(const nlohmann::json &j, Error &e); // NOLINT
        };

        inline void from_json(const nlohmann::json &j, Error &e) { // NOLINT
            e.code = j.at("code");
            e.message = j.at("message");
        }

        class ErrorResponse {
        public:
            const Error &getError() const;

        private:
            friend void from_json(const nlohmann::json &j, ErrorResponse &e); // NOLINT

            Error error;
        };

        inline void from_json(const nlohmann::json &j, ErrorResponse &e) { // NOLINT
            e.error = j.at("error");
        }
    }  // namespace Response
}  // namespace Apixu

#endif  // INCLUDE_APIXU_RESPONSE_ERROR_H_
