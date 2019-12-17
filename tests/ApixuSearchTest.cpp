// Copyright 2019 <Andrei Avram>
#include <map>
#include <string>

#include "gtest/gtest.h"
#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include "HttpClientMock.cpp"


namespace {
    using std::string;
    using std::map;

    class ApixuSearchTest : public ::testing::Test {
    public:
        const string url = "http://localhost:5000/search.json";
        const char *apiKey = "apikey";
        const string q = "Paris";
        map<string, string> params;

    protected:
        void SetUp() override {
            params["key"] = apiKey;
            params["q"] = q;
        }
    };

    TEST_F(ApixuSearchTest, success) {
        int status = 200;
        string body = R"(
           [
               {
                  "id":988,
                  "name":"ABCDEFG",
                  "region":"ABCDEFGHI",
                  "country":"ABCDEFGHIJKLMNOPQRSTUVW",
                  "lat":861.75,
                  "lon":-72.75,
                  "url":"ABCDEFGHIJKLMNOPQ"
               }
           ]
        )";

        auto mockHttpClient = HttpClientMock::GetHttpClient(url, params, status, body);

        auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
        auto search = apixu->Search(q);

        EXPECT_EQ(988, *search[0].getId());
        EXPECT_EQ("ABCDEFG", search[0].getName());
        EXPECT_EQ("ABCDEFGHI", search[0].getRegion());
        EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVW", search[0].getCountry());
        EXPECT_EQ(861.75, search[0].getLat());
        EXPECT_EQ(-72.75, search[0].getLon());
        EXPECT_EQ("ABCDEFGHIJKLMNOPQ", *search[0].getUrl());

        delete apixu;
    }

    TEST_F(ApixuSearchTest, error) {
        int status = 400;
        string body = R"(
            {
                "error": {
                  "message":"err",
                  "code":1
               }
            }
        )";

        auto mockHttpClient = HttpClientMock::GetHttpClient(url, params, status, body);
        auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);

        ASSERT_THROW(apixu->Search(q), Apixu::Exception::ApiException);

        delete apixu;
    }
}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
