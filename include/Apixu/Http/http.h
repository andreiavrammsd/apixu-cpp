// Copyright 2020 <Andrei Avram>
#ifndef INCLUDE_APIXU_HTTP_HTTP_H_
#define INCLUDE_APIXU_HTTP_HTTP_H_

#include <map>
#include <string>

namespace apixu {
namespace http {
const int STATUS_INTERNAL_SERVER_ERROR = 500;
const int STATUS_BAD_REQUEST = 400;

class Response {
   public:
    Response(int status, std::string body);

    virtual int getStatus() const;

    virtual const std::string& getBody() const;

    virtual ~Response() = default;

   private:
    int status_;
    std::string body_;
};

class Http {
   public:
    virtual const Response* get(
        const std::string& path,
        std::map<std::string, std::string> params) const = 0;

    virtual const Response* get(const std::string& path) const = 0;

    virtual ~Http() = default;
};

class Client : public Http {
   public:
    explicit Client(std::string userAgent);

    const Response* get(
        const std::string& url,
        std::map<std::string, std::string> params) const override;

    const Response* get(const std::string& url) const override;

   private:
    std::string userAgent;
};
}  // namespace http
}  // namespace apixu

#endif  // INCLUDE_APIXU_HTTP_HTTP_H_
