#include "CppUTest/TestHarness.h"
#include <dirent.h>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Result.h"
#include "FRLValidator.h"

std::vector<std::string> getTests(std::string path)      
{
    DIR    *dir;
    dirent *pdir;
    std::vector<std::string> files;
    dir = opendir(path.c_str());
    while ((pdir = readdir(dir)))  {
        char *startMatch = std::strstr(pdir->d_name, ".frl");
    	if(startMatch){
            std::string file(pdir->d_name);
            files.push_back(file.substr(0,startMatch - pdir->d_name));
        }
    }
    return files;
}

std::string readFile(std::string filename) {
    std::ifstream in(filename);
    return (std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
}


void testPhase(std::string phase) {
    string baseDir = "./tests/TagParser/" + phase + "/";
    std::vector<std::string> files = getTests(baseDir);
    for(std::string file : files) {
        ifstream infrl(baseDir + file + ".frl", ifstream::in);
        std::cout << file << std::endl;

        FRLValidator validator;
        Result result = validator.parse(&infrl);

        Result expectedResult(readFile(baseDir + file + ".result"));

        CHECK(expectedResult.isValid() == result.isValid());
        if(!expectedResult.isValid()) {
            CHECK(expectedResult.getErrorType() == result.getErrorType());
            CHECK(expectedResult.getLineError() == result.getLineError());
        }

    }   
}

TEST_GROUP(tagParser){};

TEST(tagParser, testValidAndInvalidResults)
{

    Result resultValid;
    CHECK(resultValid.isValid());
    Result resultInvalid(10, ErrorType::WRONG_CHAR_IN_TAG_NAME);
    CHECK_EQUAL(10, resultInvalid.getLineError());
    CHECK(ErrorType::WRONG_CHAR_IN_TAG_NAME == resultInvalid.getErrorType());

}

TEST(tagParser, testParseResultFromFile)
{

    std::ifstream json("./tests/test.json");
    std::string jsonString((std::istreambuf_iterator<char>(json)),
                     std::istreambuf_iterator<char>());

    Result result(jsonString);
    CHECK_FALSE(result.isValid());
    CHECK_EQUAL(3, result.getLineError());
    CHECK(ErrorType::WRONG_NUMBER_CHARS_IN_TAG == result.getErrorType());

}

TEST(tagParser, phaseA)
{

    testPhase("PhaseA");

}