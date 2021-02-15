// Queue Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale
// Credits to the owners of Techie Delight: https://www.techiedelight.com/queue-implementation-using-templates-cpp/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#define GROWTH_FACTOR 2

#include <algorithm>
#include <cstdint>

template <class T>
class queue
{
private:
    size_t front, rear, length;
    size_t capacity;
    
    T* items;

    void shrink(size_t newCapacity);
    void expand(size_t newCapacity);
    void allocate(size_t newCapacity);

public:

    bool isEmpty();
    bool isFull();

    T peek();

    void makeEmpty();
    
    void enqueue(T item);
    void dequeue(T item);
    
    queue();
    queue(size_t newCapacity);
    ~queue();
};

template <class T>
bool queue<T>::isEmpty()
{
    return (items == nullptr || length = 0 || capacity == 0);
}

template <class T>
bool queue<T>::isFull()
{
    return length == capacity;
}

template <class T>
void queue<T>::shrink(size_t newCapacity)
{
    if (items == nullptr)
        return;
    
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;

    if (length > newCapacity)
    {
        std::move(&items[front], &items[newCapacity - 1], temp);
        //std::copy_n(&items[front], newCapacity, temp);
        length = capacity;
    }
    else
        std::move(&items[front], &items[length - 1], temp);
        //std::copy_n(&items[front], length, temp);

    capacity = newCapacity;

    delete[] items;
    items = temp;
}

template <class T>
void queue<T>::expand(size_t newCapacity)
{
    if (items == nullptr)
        return;
    
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;

    std::fill_n(temp, newCapacity, T());
    std::move(&items[front], &items[length - 1], temp);
    //std::copy_n(&items[front], length, temp);

    capacity = newCapacity;

    delete[] items;
    items = temp;
}

template <class T>
void queue<T>::allocate(size_t newCapacity)
{
    T* temp = new T[newCapacity];
    if (!newCapacity)
        return;

    if (!isEmpty())
    {
        if (length < newCapacity)
        {
            std::move(&items[front], &items[newCapacity - 1], temp);
            //std::copy_n(&items[front], newCapacity, temp);
        }
        else
        {
            std::fill_n(temp, newCapacity, T());
            std::move(&items[front], &items[length - 1], temp);
            //std::copy_n(&items[front], length, temp);
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
void queue<T>::makeEmpty()
{
    delete[] items;
    length = 0, capacity = 0, front = 0, rear = -1;
}

template <class T>
T queue<T>::peek()
{
    if (isEmpty())
        return T();

    return items[front]; 
}

template <class T>
void queue<T>::enqueue(T item)
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

        if (capacity == testCapacity)
            return;
    }

    front = (front + 1) % capacity;

    item = items[front];

    length++;
}

template <class T>
void queue<T>::dequeue(T item)
{
    if (isEmpty())
        return;

    rear = (rear + 1) % capacity;

    ~items[--length];

    if (length < (capacity / GROWTH_FACTOR))
        shrink(capacity / GROWTH_FACTOR);
}

template <class T>
queue<T>::queue()
{
    length = 0, capacity = 0, front = 0, rear = -1;
    items = nullptr;
}

template <class T>
queue<T>::queue(size_t newCapacity)
{
    allocate(newCapacity);
    length = 0, capacity = newCapacity;
}

template <class T>
queue<T>::~queue()
{
    delete[] start;
}

#endif