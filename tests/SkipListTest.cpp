#include "CppUTest/TestHarness.h"
#include "SkipList.h"

TEST_GROUP(skipListTest)
{

    void setup()
    {
//        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown()
    {
//        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(skipListTest, testSkipListInsert)
{
	SkipList sl;
	sl.insert(1,"hola");
	sl.insert(2,"mundo");
    sl.insert(3,"feliz");
    std::string esl = "((1,hola),(2,mundo),(3,feliz))";
    CHECK(esl == sl.toString());
    sl.insert(3,"alegre");
    esl = "((1,hola),(2,mundo),(3,alegre))";
    CHECK(esl == sl.toString());
}

TEST(skipListTest, testSkipListErase)
{
    SkipList sl;
    sl.insert(1,"hola");
    sl.insert(2,"mundo");
    sl.insert(3,"feliz");
    sl.erase(1);
    std::string esl = "((2,mundo),(3,feliz))";
    CHECK(esl == sl.toString());
}

TEST(skipListTest, testSkipListFind)
{
    SkipList sl;
    sl.insert(1,"hola");
    sl.insert(2,"mundo");
    sl.insert(3,"feliz");

    SkipNode* sn = sl.find(2);
    CHECK(sn != nullptr);
    sn = sl.find(4);
    CHECK(sn == nullptr);

}