// Copyright 2020 <Andrei Avram>
#ifndef INCLUDE_APIXU_HTTP_HTTP_H_
#define INCLUDE_APIXU_HTTP_HTTP_H_

#include <map>
#include <string>

namespace apixu {
namespace http {
const int STATUS_INTERNAL_SERVER_ERROR = 500;
const int STATUS_BAD_REQUEST = 400;

struct Response {
    int status{};
    std::string body;
};

class Http {
   public:
    virtual Response get(const std::string& path, const std::map<std::string, std::string>& params) const = 0;

    virtual Response get(const std::string& path) const = 0;

    virtual ~Http() = default;
};

class Client : public Http {
   public:
    explicit Client(std::string userAgent);

    Response get(const std::string& url, const std::map<std::string, std::string>& params) const override;

    Response get(const std::string& url) const override;

   private:
    std::string user_agent_;
};
}  // namespace http
}  // namespace apixu

#endif  // INCLUDE_APIXU_HTTP_HTTP_H_
