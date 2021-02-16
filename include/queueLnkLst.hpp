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
    listNode<T>* front;
    listNode<T>* rear;
public:

    bool isEmpty();
    bool isFull();

    size_t size() const { return length; }

    T peek();

    void makeEmpty();
    void enqueue(T item);
    void dequeue(T item);
    
    queue();
    ~queue();
};

template <class T>
bool queue<T>::isEmpty()
{
    return front == nullptr || length == 0;
}

template <class T>
bool queue<T>::isFull()
{
    listNode<T>* test = new listNode<T>;
    
    if (!test)
        return true;

    delete test;

    return false;
}

template <class T>
T queue<T>::peek()
{
    if (front == nullptr)
        return T();
        // throw "attempted to access empty queue"
    else
        return front->value;
}

template <class T>
void queue<T>::makeEmpty()
{
    while (front != nullptr)
    {
        listNode<T>* temp = front;
        front = front->next;
        delete temp;
    }
    rear = front;
    length = 0;
}

template <class T>
void queue<T>::enqueue(T item)
{
    if (isFull())
        return;
        // throw "cannot allocate more objects for queue"
    
    listNode<T>* newNode = new listNode<T>;

    if (!newNode)
        return;

    newNode->value = item;

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = rear->next;
    }

    length++;
}

template <class T>
void queue<T>::dequeue(T item)
{
    if (isEmpty())
        return;

    listNode<T>* node = front;
    front = front->next;
    delete node;

    if (front == nullptr)
        rear = nullptr;

    length--;
}

template <class T>
queue<T>::queue(/* args */)
{
    length = 0;
    front = nullptr;
    rear = nullptr;
}

template <class T>
queue<T>::~queue()
{
    makeEmpty();
}

#endif