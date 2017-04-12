#include "CppUTest/TestHarness.h"
#include <dirent.h>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

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

std::string readFile(td::string filename) {
    std::ifstream in(filename, std::ios::in);
    if (in) {
        return (std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
    }
    throw (errno);
}


void testPhase(std::string phase) {
    string baseDir = "./tests/TagParser/";
    std::vector<std::string> files = getTests(baseDir + phase);
    for(std::string file : files) {
        ifstream infrl, inresult;

        infrl.open(baseDir + file + ".frl", ifstream::in);
        if (!infrl.is_open()) {
            string msg = "Error: Can not read -> " + mfile;
            cout << msg << endl;
            throw msg;

        }

        MMLValidator validator;
        Result result = validator.parse(&infrl);

        Result expectedResult;
        result.fromJson(readFile(baseDir + file + ".result"));

        ASSERT_EQUAL(expectedResult->getSuccesful(), result->getSuccesful());
        ASSERT_EQUAL(expectedResult->getLine(), result->getLine());
        ASSERT_EQUAL(expectedResult->getErrorType(), result->getErrorType());

        infrl.close();
        inresult.close();
    }   
}

TEST_GROUP(tagParser){};

TEST(tagParser, phaseA)
{

    testPhase("PhaseA");

}