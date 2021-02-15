// Queue Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdint>

#include "linkedListNode.hpp"

template <class T>
class queue
{
    
private:
    size_t length;
    listNode<T>* start;
    listNode<T>* end;
public:

    bool isEmpty();
    bool isFull();

    void makeEmpty();
    void enqueue(T item);
    void dequeue(T item);
    
    queue();
    ~queue();
};

template <class T>
bool queue<T>::isEmpty()
{
    return start == nullptr || length == 0;
}

template <class T>
bool queue<T>::isFull()
{
    listNode<T>* test = new listNode;
    
    if (!test)
        return true;

    delete test;

    return false;
}

template <class T>
void queue<T>::makeEmpty()
{
    while (start != nullptr)
    {
        listNode<T>* temp = start;
        start = start->next;
        delete temp;
    }
    end = start;
    length = 0;
}

template <class T>
void queue<T>::enqueue(T item)
{
    if (isFull())
        return;
    
    listNode<T>* newNode = new listNode<T>;

    if (!newNode)
        return;

    newNode->value = item;

    if (start == nullptr)
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        end->next = newNode;
        end = end->next;
    }

    length++;
}

template <class T>
void queue<T>::dequeue(T item)
{
    if (isEmpty())
        return;

    listNode<T>* node = start;
    start = start->next;
    delete node;

    if (start == nullptr)
        end = nullptr;

    length--;
}

template <class T>
queue<T>::queue(/* args */)
{
    length = 0;
    start = nullptr;
    end = nullptr;
}

template <class T>
queue<T>::~queue()
{
    makeEmpty();
}

#endif