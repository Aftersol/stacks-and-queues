// Linked List Based Queue Implementation Test by Aftersol 2021

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queueLnkLst.hpp"

TEST_CASE("Test Intialization")
{
    queue<int> testQueueLinkedList;
    REQUIRE(testQueueLinkedList.size() == 0);

    testQueueLinkedList.enqueue(1);

    REQUIRE(testQueueLinkedList.size() == 1);
    REQUIRE(testQueueLinkedList.peek() == 1);
}

TEST_CASE("Allocate Test")
{
    queue<int> testQueueLinkedList;
    REQUIRE(testQueueLinkedList.size() == 0);

    for (int i = 0; i < 100; i++)
    {
        testQueueLinkedList.enqueue(i);
        REQUIRE(testQueueLinkedList.peek() == 0);
    }

    REQUIRE(testQueueLinkedList.size() == 100);
}

TEST_CASE("Deallocate Test")
{
    queue<int> testQueueLinkedList;

    for (int i = 0; i < 128; i++)
    {
        testQueueLinkedList.enqueue(i);
        REQUIRE(testQueueLinkedList.peek() == 0);
    }

    for (int i = 0; i < 100; i++)
    {
        testQueueLinkedList.dequeue(i);
    }

    REQUIRE(testQueueLinkedList.peek() == 100);
    REQUIRE(testQueueLinkedList.size() == 28);
}

TEST_CASE("Purge Test")
{
    queue<int> testQueueLinkedList;

    for (int i = 0; i < 10; i++)
    {
        testQueueLinkedList.enqueue(i);
        REQUIRE(testQueueLinkedList.peek() == 0);
    }

    for (int i = 0; i < 10; i++)
    {
        testQueueLinkedList.dequeue(i);
    }

    REQUIRE(testQueueLinkedList.peek() == int());
    REQUIRE(testQueueLinkedList.size() == 0);
}