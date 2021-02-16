// Array Based Stack Implementation Test by Aftersol

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stackArr.hpp"

TEST_CASE("Stack Initalization")
{
    stack<int> a;

    REQUIRE(a.size() == 0);
    REQUIRE(a.getCapacity() == 0);

    a.push(1);

    REQUIRE(a.top() == 1);
}

TEST_CASE("Stack Allocate")
{
    stack<int> a;

    for (int i = 0; i < 100; i++)
    {
        a.push(i);
        REQUIRE(a.top() == 0);
    }

    REQUIRE(a.size() == 100);
    REQUIRE(a.getCapacity() == 128);
}

TEST_CASE("Stack Deallocate")
{
    stack<int> a;

    for (int i = 0; i < 100; i++)
    {
        a.push(i);
        REQUIRE(a.top() == 0);
    }

    REQUIRE(a.size() == 100);
    REQUIRE(a.getCapacity() == 128);

    for (int i = 98; i > 48; i--)
    {
        a.pop();
        REQUIRE(a.top() == i);
    }
    
    REQUIRE(a.size() == 50);
    REQUIRE(a.getCapacity() == 64);
}
