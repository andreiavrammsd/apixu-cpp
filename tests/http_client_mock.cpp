// Copyright 2020 <Andrei Avram>
#include <map>
#include <string>
#include <utility>

#include "Apixu/Http/http.h"
#include "gmock/gmock.h"

namespace apixutest {
using std::map;
using std::string;
using ::testing::Return;
using ::testing::ReturnRef;

class HttpClientMock : public apixu::http::Http {
   public:
    MOCK_METHOD(apixu::http::Response, get, (const string&, (const map<string, string>&)), (const override));
    MOCK_METHOD(apixu::http::Response, get, (const string&), (const override));

    static auto GetClient(const string& url, const map<string, string>& params, int status, const string& body)
    {
        auto mockHttpResponse = apixu::http::Response{status, body};
        auto mock_http_client = std::make_unique<HttpClientMock>();
        EXPECT_CALL(*mock_http_client, get(url, params)).Times(1).WillOnce(Return(mockHttpResponse));

        return mock_http_client;
    }

    static auto GetHttpClient(const string& url, int status, const string& body)
    {
        map<string, string> params;
        return GetClient(url, params, status, body);
    }
};

}  // namespace apixutest
