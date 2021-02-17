// Stack Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale

#ifndef STACK_HPP
#define STACK_HPP

#define GROWTH_FACTOR 2 // THIS GROWTH EXPONENT FACTOR IS CHOSEN TO MINIMIZE PERFORMANCE LOSS BECAUSE
                        // OF MEMORY ALLOCATION: https://en.wikipedia.org/wiki/Dynamic_array#Growth_factor

#include <algorithm>
#include <cstdint>

template <class T>
class stack
{
private:
    size_t length, capacity;
    T* items;

    // Functions for automatic resizing of the stack

    void shrink(size_t newCapacity);
    void expand(size_t newCapacity);
    void allocate(size_t newCapacity);

public:

    bool isEmpty();
    bool isFull();

    size_t size() const { return length; }
    size_t getCapacity() const { return capacity; }

    void push(T item);
    void pop();

    T top();

    stack();
    stack(T item);
    ~stack();
};

template <class T>
bool stack<T>::isEmpty()
{
    return (items == nullptr || length == 0 || capacity == 0);
}

template <class T>
bool stack<T>::isFull()
{
    return length == capacity;
}

template <class T>
void stack<T>::shrink(size_t newCapacity)
{
    if (items == nullptr)
        return;
    
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;
        // throw "cannot allocate objects for stack"

    if (length > newCapacity)
    {
        //std::copy_n(&items[0], newCapacity, temp);
        std::move(&items[0], &items[newCapacity], temp);
        length = capacity;
    }
    else
        std::move(&items[0], &items[length], temp);
        //std::copy_n(&items[0], length, temp);

    capacity = newCapacity;

    delete[] items;
    items = temp;
}

template <class T>
void stack<T>::expand(size_t newCapacity)
{
    if (items == nullptr)
        return;
    
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;
        // throw "cannot allocate more objects for stack"

    std::fill_n(temp, newCapacity, T());
    //std::copy_n(&items[0], length, temp);
    std::move(&items[0], &items[length], temp);
    delete[] items;

    capacity = newCapacity;

    items = temp;


}

template <class T>
void stack<T>::allocate(size_t newCapacity)
{
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;
        // throw "cannot allocate more objects for stack"

    if (!isEmpty())
    {
        if (length < newCapacity)
        {
            //std::copy_n(&items[0], newCapacity, temp);
            std::move(&items[0], &items[newCapacity], temp);
        }
        else
        {
            std::fill_n(temp, newCapacity, T());
            //std::copy_n(&items[0], length, temp);
            std::move(&items[0], &items[length], temp);
        }

        delete[] items;
        items = temp;
    }
    else
    {
        items = temp;
    }
    capacity = newCapacity;
}

template <class T>
void stack<T>::push(T item)
{
    if (isEmpty())
    {
        if (capacity == 0 || items == nullptr)
            allocate(1);

        if (capacity == 0 || items == nullptr)
            return;
            // throw "cannot reserve more objects for stack"
    }

    if (isFull())
    {
        size_t testCapacity = capacity;

        expand(capacity * GROWTH_FACTOR);
        
        if (testCapacity == capacity)
            return;
            // throw "cannot reserve more objects for stack"
    }

    items[length++] = item;
}

template <class T>
void stack<T>::pop()
{
    if (isEmpty())
        return;

    items[--length] = T();

    if (length < capacity / GROWTH_FACTOR)
        shrink(capacity / GROWTH_FACTOR);
}

template <class T>
T stack<T>::top()
{
    if (isEmpty())
        return T();
        // throw "attempted to access empty stack"

    return items[length - 1];

}

template <class T>
stack<T>::stack()
{
    length = 0;
    capacity = 0;
}

template <class T>
stack<T>::stack(T item)
{
    length = 0;
    capacity = 0;

    T* items = new T[1];
    if (!items)
        return;
        // throw "cannot allocate more objects for stack"
    
    else
    {
        items[length++] = item;
        capacity = 1;
        length = 1;
    }
}

template <class T>
stack<T>::~stack()
{
    delete[] items;
}


#endif