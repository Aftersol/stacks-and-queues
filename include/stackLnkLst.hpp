// Stack Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale

#ifndef STACK_HPP
#define STACK_HPP

#include <cstdint>

#include "linkedListNode.hpp"

template <class T>
class stack
{

private:
    size_t length;

    listNode<T>* end;
public:
    stack(/* args */);
    ~stack();

    bool isEmpty();
    bool isFull();

    void push(T item);
    void pop();

    T top();
};

template <class T>
bool stack<T>::isEmpty()
{
    return (end == nullptr || length = 0);
}

template <class T>
bool stack<T>::isFull()
{
    listNode<T>* test = new listNode<T>;
    
    if (!test)
        return true;

    delete test;

    return false;
}

template <class T>
void stack<T>::push(T item)
{
    if (isFull())
        return;

    listNode<T>* newNode = new listNode<T>;

    if (!newNode)
        return;

    newNode->value = item;

    newNode->next = end;

    end = newNode;

    length++;
}

template <class T>
void stack<T>::pop()
{
    if (isEmpty())
        return;
    
    listNode<T>* temp = end;
    end = end->next;
    delete temp;

    length--;
}

template <class T>
T stack<T>::top()
{
    if (end == nullptr)
        return T();
    
    else
        return end->value;
}


template <class T>
stack<T>::stack(/* args */)
{
    end = nullptr;
    length = 0;
}

template <class T>
stack<T>::~stack()
{
    while (end != nullptr)
    {
        listNode<T>* temp = end;
        end = end->next;
        delete temp;
    }
}


#endif