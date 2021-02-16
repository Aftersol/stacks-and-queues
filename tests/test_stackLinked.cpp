// Linked List Based Stack Implementation Test by Aftersol 2021

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stackLnkLst.hpp"

TEST_CASE("Stack Initization")
{
    stack<int> testStackLinkedList;

    REQUIRE(testStackLinkedList.size() == 0);

    testStackLinkedList.push(1);

    REQUIRE(testStackLinkedList.top() == 1);
}

TEST_CASE("Stack Allocate")
{
    stack<int> testStackLinkedList;

    for (int i = 0; i < 100; i++)
    {
        testStackLinkedList.push(i);
        REQUIRE(testStackLinkedList.top() == i);
    }

    REQUIRE(testStackLinkedList.size() == 100);
}

TEST_CASE("Stack Deallocate")
{
    stack<int> testStackLinkedList;

    for (int i = 0; i < 100; i++)
    {
        testStackLinkedList.push(i);
        REQUIRE(testStackLinkedList.top() == i);
    }

    REQUIRE(testStackLinkedList.size() == 100);

    for (int i = 98; i > 48; i--)
    {
        testStackLinkedList.pop();
        REQUIRE(testStackLinkedList.top() == i);
    }
    
    REQUIRE(testStackLinkedList.size() == 50);
}

TEST_CASE("Purge Test")
{
    stack<int> testStackLinkedList;

    for (int i = 0; i < 10; i++)
    {
        testStackLinkedList.push(i);
        REQUIRE(testStackLinkedList.top() == i);
    }

    for (int i = 0; i < 10; i++)
    {
        testStackLinkedList.pop();
    }

    REQUIRE(testStackLinkedList.top() == int());
    REQUIRE(testStackLinkedList.size() == 0);
}