#include "../src/Apixu.hpp"
#include "../src/Exception/ApixuException.cpp"
#include "gmock/gmock.h"

namespace HttpClientMock {
    class MockHttpResponse : public Apixu::Http::Response {
    public:
        MockHttpResponse(int status, string body) : Response(status, std::move(body)) {}

        MOCK_METHOD(int, getStatus, (), (const, override));
        MOCK_METHOD(const string&, getBody, (), (const, override));
    };

    class MockHttpClient : public Apixu::Http::Http {
    public:
        explicit MockHttpClient() = default;

        MOCK_METHOD(const Apixu::Http::Response*, get, (const string&, (const map<string, string>*)), (override));
    };

    using ::testing::Return;
    using ::testing::ReturnRef;

    MockHttpClient *GetHttpClient(const string &url, map<string, string> *params, int status, const string &body) {
        auto mockHttpResponse = new MockHttpResponse(status, body);
        EXPECT_CALL(*mockHttpResponse, getStatus())
                .Times(1)
                .WillOnce(Return(status));
        EXPECT_CALL(*mockHttpResponse, getBody())
                .Times(1)
                .WillOnce(ReturnRef(body));

        auto mockHttpClient = new MockHttpClient();
        EXPECT_CALL(*mockHttpClient, get(url, params))
                .Times(1)
                .WillOnce(Return(mockHttpResponse));

        return mockHttpClient;
    }
}
