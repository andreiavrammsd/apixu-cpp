// Copyright 2020 <Andrei Avram>
#include <string>

#include "Apixu/Exception/api_exception.h"
#include "Apixu/apixu.h"
#include "gtest/gtest.h"
#include "http_client_mock.cpp"

namespace apixutest {
using std::string;

class ApixuConditionsTest : public ::testing::Test {
   public:
    const string url_ = "http://localhost:5000/conditions.json";
};

TEST_F(ApixuConditionsTest, success)
{
    int status = 200;
    string body = R"(
            [
               {
                  "code":1,
                  "day":"day",
                  "night":"night",
                  "icon":22
               }
            ]
        )";

    auto mock_http_client = HttpClientMock::GetHttpClient(url_, status, body);
    apixu::Apixu apixu{"", std::move(mock_http_client)};

    const auto& conditions = apixu.Conditions();

    EXPECT_EQ(1, conditions.size());
    EXPECT_EQ(1, conditions[0].code);
    EXPECT_EQ("day", conditions[0].day);
    EXPECT_EQ("night", conditions[0].night);
    EXPECT_EQ(22, conditions[0].icon);
}

TEST_F(ApixuConditionsTest, error)
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

    auto mock_http_client = HttpClientMock::GetHttpClient(url_, status, body);
    apixu::Apixu apixu{"", std::move(mock_http_client)};

    EXPECT_THROW(apixu.Conditions(), apixu::exception::ApixuException);
}
}  // namespace apixutest
