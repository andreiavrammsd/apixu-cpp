// Copyright 2019 <Andrei Avram>
#include <string>

#include "Apixu/Apixu.h"
#include "Apixu/Exception/ApiException.h"
#include "HttpClientMock.cpp"
#include "gtest/gtest.h"

namespace ApixuTest {
using std::string;

class ApixuConditionsTest : public ::testing::Test {
   public:
    const string url = "http://localhost:5000/conditions.json";
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

    auto mockHttpClient = HttpClientMock::GetHttpClient(url, status, body);

    auto apixu = new Apixu::Apixu("", mockHttpClient);
    auto conditions = apixu->Conditions();

    EXPECT_EQ(1, conditions.size());
    EXPECT_EQ(1, conditions[0].getCode());
    EXPECT_EQ("day", conditions[0].getDay());
    EXPECT_EQ("night", conditions[0].getNight());
    EXPECT_EQ(22, conditions[0].getIcon());

    delete apixu;
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

    auto mockHttpClient = HttpClientMock::GetHttpClient(url, status, body);
    auto apixu = new Apixu::Apixu("", mockHttpClient);

    ASSERT_THROW(apixu->Conditions(), Apixu::Exception::ApixuException);

    delete apixu;
}
}  // namespace ApixuTest
