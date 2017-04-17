#include "CppUTest/TestHarness.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "rapidjson/document.h"

TEST_GROUP(rapidjsonTest)
{

};

TEST(rapidjsonTest, testParseJsonFromFile)
{

	std::ifstream json("./tests/test.json");
	std::string	jsonString((std::istreambuf_iterator<char>(json)),
	                 std::istreambuf_iterator<char>());

	rapidjson::Document document;
    document.Parse<0>(jsonString.c_str());
    CHECK(document.HasMember("valid"));
    CHECK_FALSE(document["valid"].GetBool());
    CHECK(document["error"]["line"].GetInt() == 3);
}
