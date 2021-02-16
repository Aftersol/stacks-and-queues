// Array Based Queue Implementation Test by Aftersol 2021

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queueArr.hpp"

TEST_CASE("Test Intialization")
{
    queue<int> testQueueArray;
    REQUIRE(testQueueArray.size() == 0);
    REQUIRE(testQueueArray.getCapacity() == 0);

    testQueueArray.enqueue(1);

    REQUIRE(testQueueArray.size() == 1);
    REQUIRE(testQueueArray.getCapacity() == 1);
    REQUIRE(testQueueArray.peek() == 1);
}

TEST_CASE("Allocate Test")
{
    queue<int> testQueueArray;

    for (int i = 0; i < 100; i++)
    {
        testQueueArray.enqueue(i);
    }

    REQUIRE(testQueueArray.size() == 100);
    REQUIRE(testQueueArray.getCapacity() == 128);
}

TEST_CASE("Deallocate Test")
{
    queue<int> testQueueArray;

    for (int i = 0; i < 128; i++)
    {
        testQueueArray.enqueue(i);
    }

    REQUIRE(testQueueArray.isFull());
    REQUIRE(testQueueArray.getCapacity() == 128);

    for (int i = 0; i < 100; i++)
    {
        testQueueArray.dequeue();
    }

    REQUIRE(testQueueArray.peek() == 100);
    REQUIRE(testQueueArray.size() == 28);
}
TEST_CASE("Overlap Test")
{
    queue<int> testQueueArray;

    for (int i = 0; i < 128; i++)
    {
        testQueueArray.enqueue(i);
    }

    REQUIRE(testQueueArray.isFull());
    REQUIRE(testQueueArray.getCapacity() == 128);

    for (int i = 0; i < 100; i++)
    {
        testQueueArray.dequeue();
    }

    for (int i = 0; i < 4; i++)
    {
        testQueueArray.enqueue(i);
    }

    REQUIRE(testQueueArray.peek() == 100);
    REQUIRE(testQueueArray.size() == 32);

    for (int i = 0; i < 17; i++)
    {
        testQueueArray.dequeue();
    }
}