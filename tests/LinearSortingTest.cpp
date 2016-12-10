#include "CppUTest/TestHarness.h"
#include "LinearSorting.h"

TEST_GROUP(linearSortingTest)
{

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(linearSortingTest, countingSortTest)
{
    LinearSorting ls;
    int unsorted_array[7] = {1, 4, 1, 2, 7, 5, 2};
    int sorted_array[7] = {1, 1, 2, 2, 4, 5, 7};
    
    std::vector<int> unsorted_vector(unsorted_array, unsorted_array + (sizeof unsorted_array / sizeof unsorted_array[0]));
    ls.counting(unsorted_vector);
     
    for (int i = 0; i < 7; i++)
    {
        CHECK(sorted_array[i] == unsorted_vector[i]);
    }
}