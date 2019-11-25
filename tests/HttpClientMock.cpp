#include "../src/Apixu.hpp"
#include "../src/Exception/ApixuException.cpp"
#include "gmock/gmock.h"

namespace HttpClientMock {
    class MockHTTPResponse : public Apixu::HTTP::Response {
    public:
        MockHTTPResponse(int status, string body) : Response(status, std::move(body)) {}

        MOCK_METHOD(int, getStatus, (), (const, override));
        MOCK_METHOD(const string&, getBody, (), (const, override));
    };

    class MockHTTP : public Apixu::HTTP::HTTP {
    public:
        explicit MockHTTP() = default;

        MOCK_METHOD(const Apixu::HTTP::Response*, get, (const string&, (const map<string, string>*)), (override));
    };

    using ::testing::Return;
    using ::testing::ReturnRef;

    MockHTTP *GetHttpClient(const string &url, map<string, string> *params, int status, const string &body) {
        auto mockHttpResponse = new MockHTTPResponse(status, body);
        EXPECT_CALL(*mockHttpResponse, getStatus())
                .Times(1)
                .WillOnce(Return(status));
        EXPECT_CALL(*mockHttpResponse, getBody())
                .Times(1)
                .WillOnce(ReturnRef(body));

        auto mockHttp = new MockHTTP();
        EXPECT_CALL(*mockHttp, get(url, params))
                .Times(1)
                .WillOnce(Return(mockHttpResponse));

        return mockHttp;
    }
}

