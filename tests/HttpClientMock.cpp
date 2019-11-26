#include "../src/Apixu.hpp"
#include "../src/Exception/ApiException.hpp"
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

        MOCK_METHOD(const Apixu::Http::Response*, get, (const string&, (map<string, string>)), (override));
        MOCK_METHOD(const Apixu::Http::Response*, get, (const string&), (override));
    };

    using ::testing::Return;
    using ::testing::ReturnRef;

    MockHttpClient *GetHttpClient(const string &url, map<string, string> params, int status, const string &body) {
        auto mockHttpResponse = new MockHttpResponse(status, body);
        EXPECT_CALL(*mockHttpResponse, getStatus())
                .Times(1)
                .WillOnce(Return(status));
        EXPECT_CALL(*mockHttpResponse, getBody())
                .Times(1)
                .WillOnce(ReturnRef(body));

        auto mockHttpClient = new MockHttpClient();
        EXPECT_CALL(*mockHttpClient, get(url, std::move(params)))
                .Times(1)
                .WillOnce(Return(mockHttpResponse));

        return mockHttpClient;
    }

    MockHttpClient *GetHttpClient(const string &url, int status, const string &body) {
        map<string, string> params;
        return GetHttpClient(url, params, status, body);
    }
}
