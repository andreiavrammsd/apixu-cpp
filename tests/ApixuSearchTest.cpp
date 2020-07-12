// Copyright 2019 <Andrei Avram>
#include <map>
#include <string>

#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include "HttpClientMock.cpp"
#include "gtest/gtest.h"

namespace ApixuTest {
using std::map;
using std::string;

class ApixuSearchTest : public ::testing::Test {
   public:
    const string url = "http://localhost:5000/search.json";
    const char *apiKey = "apikey";
    const string q = "Paris";
    map<string, string> params;

   protected:
    void SetUp() override
    {
        params["key"] = apiKey;
        params["q"] = q;
    }
};

TEST_F(ApixuSearchTest, success)
{
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

    auto mockHttpClient = HttpClientMock::GetClient(url, params, status, body);

    auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);
    auto search = apixu->Search(q);

    EXPECT_EQ(988, *search[0].id);
    EXPECT_EQ("ABCDEFG", search[0].name);
    EXPECT_EQ("ABCDEFGHI", search[0].region);
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVW", search[0].country);
    EXPECT_EQ(861.75, search[0].lat);
    EXPECT_EQ(-72.75, search[0].lon);
    EXPECT_EQ("ABCDEFGHIJKLMNOPQ", *search[0].url);

    delete apixu;
}

TEST_F(ApixuSearchTest, error)
{
    int status = 400;
    string body = R"(
            {
                "error": {
                  "message":"err",
                  "code":1
               }
            }
        )";

    auto mockHttpClient = HttpClientMock::GetClient(url, params, status, body);
    auto apixu = new Apixu::Apixu(apiKey, mockHttpClient);

    EXPECT_THROW(apixu->Search(q), Apixu::Exception::ApiException);

    delete apixu;
}
}  // namespace ApixuTest
