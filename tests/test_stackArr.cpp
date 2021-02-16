// Array Based Stack Implementation Test by Aftersol 2021

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stackArr.hpp"

TEST_CASE("Stack Initalization")
{
    stack<int> testStackArray;

    REQUIRE(testStackArray.size() == 0);
    REQUIRE(testStackArray.getCapacity() == 0);

    testStackArray.push(1);

    REQUIRE(testStackArray.top() == 1);
}

TEST_CASE("Stack Allocate")
{
    stack<int> testStackArray;

    for (int i = 0; i < 100; i++)
    {
        testStackArray.push(i);
        REQUIRE(testStackArray.top() == i);
    }

    REQUIRE(testStackArray.size() == 100);
    REQUIRE(testStackArray.getCapacity() == 128);
}

TEST_CASE("Stack Deallocate")
{
    stack<int> testStackArray;

    for (int i = 0; i < 100; i++)
    {
        testStackArray.push(i);
        REQUIRE(testStackArray.top() == i);
    }

    REQUIRE(testStackArray.size() == 100);
    REQUIRE(testStackArray.getCapacity() == 128);

    for (int i = 98; i > 48; i--)
    {
        testStackArray.pop();
        REQUIRE(testStackArray.top() == i);
    }
    
    REQUIRE(testStackArray.size() == 50);
    REQUIRE(testStackArray.getCapacity() == 64);
}
