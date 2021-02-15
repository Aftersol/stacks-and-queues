// Stack Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale

#ifndef STACK_HPP
#define STACK_HPP

#define GROWTH_FACTOR 2

#include <algorithm>
#include <cstdint>

template <class T>
class stack
{
private:
    size_t length, capacity;
    T* items;

    void shrink(size_t newCapacity);
    void expand(size_t newCapacity);
    void allocate(size_t newCapacity);

public:

    bool isEmpty();
    bool isFull();

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
    return (items == nullptr || length = 0 || capacity == 0);
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

    if (length > newCapacity)
    {
        //std::copy_n(&items[0], newCapacity, temp);
        std::move(&items[0], &items[newCapacity - 1], temp);
        length = capacity;
    }
    else
        std::move(&items[0], &items[length - 1], temp);
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

    std::fill_n(temp, T(), newCapacity);
    //std::copy_n(&items[0], length, temp);
    std::move(&items[0], &items[length - 1], temp);
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

    if (!isEmpty())
    {
        if (length < newCapacity)
        {
            //std::copy_n(&items[0], newCapacity, temp);
            std::move(&items[0], &items[newCapacity - 1], temp);
        }
        else
        {
            std::fill_n(temp, newCapacity, T());
            //std::copy_n(&items[0], length, temp);
            std::move(&items[0], &items[length - 1], temp);
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
    }

    if (isFull())
    {
        size_t testCapacity = capacity;

        expand(capacity * GROWTH_FACTOR);
        
        if (testCapacity == capacity)
            return;
    }

    items[length++] = item;
}

template <class T>
void stack<T>::pop()
{
    items[--length] = T();

    if (length < capacity / GROWTH_FACTOR)
        shrink(capacity < / GROWTH_FACTOR);
}

template <class T>
T stack<T>::top()
{
    if (isEmpty())
        return T();

    return items[length - 1];

}

template <class T>
stack<T>::stack()
{
}

template <class T>
stack<T>::stack(T item)
{
    length = 0;
    capacity = 0;

    T* items = new T[1];
    if (!items)
        return;
    
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