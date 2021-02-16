#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queueLnkLst.hpp"

TEST_CASE("Test Intialization")
{
    queue<int> a;
    REQUIRE(a.size() == 0);

    a.enqueue(1);

    REQUIRE(a.size() == 1);
    REQUIRE(a.peek() == 1);
}

TEST_CASE("Allocate Test")
{
    queue<int> a;
    REQUIRE(a.size() == 0);

    for (int i = 0; i < 100; i++)
    {
        a.enqueue(i);
        REQUIRE(a.peek() == 0);
    }

    REQUIRE(a.size() == 100);
}

TEST_CASE("Deallocate Test")
{
    queue<int> a;

    for (int i = 0; i < 128; i++)
    {
        a.enqueue(i);
        REQUIRE(a.peek() == 0);
    }

    for (int i = 0; i < 100; i++)
    {
        a.dequeue(i);
    }

    REQUIRE(a.peek() == 100);
    REQUIRE(a.size() == 28);
}

TEST_CASE("Purge Test")
{
    queue<int> a;

    for (int i = 0; i < 10; i++)
    {
        a.enqueue(i);
        REQUIRE(a.peek() == 0);
    }

    for (int i = 0; i < 100; i++)
    {
        a.dequeue(i);
    }

    REQUIRE(a.peek() == int());
    REQUIRE(a.size() == 0);
}