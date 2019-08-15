#ifndef APIXU_DEV_ERROR_H
#define APIXU_DEV_ERROR_H


#include "include/nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

namespace Apixu {
    class Error {
    public:
        int getCode() const;

        const string &getMessage() const;

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
        const Error &getError() const {
            return error;
        }

    private:
        friend void from_json(const json &j, ErrorResponse &e);
        Error error;
    };

    inline void from_json(const json &j, ErrorResponse &e) {
        e.error = j.at("error").get<Error>();
    }
}


#endif //APIXU_DEV_ERROR_H
