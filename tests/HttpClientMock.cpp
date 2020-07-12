// Copyright 2019 <Andrei Avram>
#include <map>
#include <string>
#include <utility>

#include "Apixu/Http/Http.h"
#include "gmock/gmock.h"

namespace ApixuTest {
using std::map;
using std::string;
using ::testing::Return;
using ::testing::ReturnRef;

class HttpResponse : public Apixu::Http::Response {
   public:
    HttpResponse(int status, const string &body) : Response(status, body) {}

    MOCK_METHOD(int, getStatus, (), (const, override));
    MOCK_METHOD(const string &, getBody, (), (const, override));
};

class HttpClientMock : public Apixu::Http::Http {
   public:
    HttpClientMock() = default;

    MOCK_METHOD(const Apixu::Http::Response *, get,
                (const string &, (map<string, string>)), (override));
    MOCK_METHOD(const Apixu::Http::Response *, get, (const string &),
                (override));

    static HttpClientMock *GetClient(const string &url,
                                     map<string, string> params, int status,
                                     const string &body)
    {
        auto mockHttpResponse = new HttpResponse(status, body);
        EXPECT_CALL(*mockHttpResponse, getStatus())
            .Times(1)
            .WillOnce(Return(status));
        EXPECT_CALL(*mockHttpResponse, getBody())
            .Times(1)
            .WillOnce(ReturnRef(body));

        auto mockHttpClient = new HttpClientMock();
        EXPECT_CALL(*mockHttpClient, get(url, std::move(params)))
            .Times(1)
            .WillOnce(Return(mockHttpResponse));

        return mockHttpClient;
    }

    static HttpClientMock *GetHttpClient(const string &url, int status,
                                         const string &body)
    {
        map<string, string> params;
        return GetClient(url, params, status, body);
    }
};

}  // namespace ApixuTest
