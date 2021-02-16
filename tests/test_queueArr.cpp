#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queueArr.hpp"


TEST_CASE("Test Intialization")
{
    queue<int> a;
    REQUIRE(a.size() == 0);
    REQUIRE(a.getCapacity() == 0);

    a.enqueue(1);

    REQUIRE(a.size() == 1);
    REQUIRE(a.getCapacity() == 1);
    REQUIRE(a.peek() == 1);
}

TEST_CASE("Allocate Test")
{
    queue<int> a;

    for (int i = 0; i < 100; i++)
    {
        a.enqueue(i);
    }

    REQUIRE(a.size() == 100);
    REQUIRE(a.getCapacity() == 128);
}

TEST_CASE("Deallocate Test")
{
    queue<int> a;

    for (int i = 0; i < 128; i++)
    {
        a.enqueue(i);
    }

    REQUIRE(a.isFull());
    REQUIRE(a.getCapacity() == 128);

    for (int i = 0; i < 100; i++)
    {
        a.dequeue();
    }

    REQUIRE(a.peek() == 100);
    REQUIRE(a.size() == 28);
}
TEST_CASE("Overlap Test")
{
    queue<int> a;

    for (int i = 0; i < 128; i++)
    {
        a.enqueue(i);
    }

    REQUIRE(a.isFull());
    REQUIRE(a.getCapacity() == 128);

    for (int i = 0; i < 100; i++)
    {
        a.dequeue();
    }

    for (int i = 0; i < 4; i++)
    {
        a.enqueue(i);
    }

    REQUIRE(a.peek() == 100);
    REQUIRE(a.size() == 32);

    for (int i = 0; i < 17; i++)
    {
        a.dequeue();
    }
}