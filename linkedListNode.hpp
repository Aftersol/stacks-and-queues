// Generic List Node Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale

#ifndef LINKED_LIST_NODE_HPP
#define LINKED_LIST_NODE_HPP

template <class T>
struct listNode
{
    T value;
    T* next;

    listNode() {
        value = T();
        next = nullptr;
    }
};

#endif