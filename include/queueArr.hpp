// Queue Implementation by Aftersol 2021
// Based on code from the book: C++ Plus Data Structures by Nell B. Dale
// Credits to the owners of Techie Delight: https://www.techiedelight.com/queue-implementation-using-templates-cpp/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#define GROWTH_FACTOR 2 // THIS GROWTH EXPONENT FACTOR IS CHOSEN TO MINIMIZE PERFORMANCE LOSS BECAUSE
                        // OF MEMORY ALLOCATION: https://en.wikipedia.org/wiki/Dynamic_array#Growth_factor

#include <algorithm>
#include <cstdint>

template <class T>
class queue
{
private:
    // Store the position of the front and rear respectively for the queue

    size_t front, rear;

    // Store the maximum size of the queue and the amount of objects on the queue

    size_t length, capacity;
    
    // An array of class objects
    T* items;

    // Functions used for automatic resizing of the queue

    void shrink(size_t newCapacity);
    void expand(size_t newCapacity);
    void allocate(size_t newCapacity);

    void moveItems(T* origin, T* dest, size_t len);

public:

    bool isEmpty(); // No objects in the array?
    bool isFull(); // Array filled up?

    size_t size() const { return length; } // How many objects in the array
    size_t getCapacity() { return capacity; } // Maximum amount of objects that can be in the array

    T peek();

    void makeEmpty(); // Destroys all the objects in the queue.
    
    void enqueue(T item);
    void dequeue();
    
    queue();
    queue(size_t newCapacity);
    ~queue();
};

template <class T>
bool queue<T>::isEmpty()
{
    return (items == nullptr || length == 0 || capacity == 0);
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
    if (!temp)
        return;
        // throw "cannot reserve more objects for queue"

    if (length > newCapacity)
    {
        std::move(&items[front], &items[newCapacity], temp);
        //std::copy_n(&items[front], newCapacity, temp);
        length = capacity;
    }
    else
        moveItems(items, temp, newCapacity);
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
    if (!temp)
        return;
        // throw "cannot reserve more objects for queue"

    std::fill_n(temp, newCapacity, T());
    moveItems(items, temp, newCapacity);
    //std::copy_n(&items[front], length, temp);

    capacity = newCapacity;

    delete[] items;
    items = temp;
}

template <class T>
void queue<T>::allocate(size_t newCapacity)
{
    T* temp = new T[newCapacity];
    if (!temp)
        return;
        // throw "cannot reserve more objects for queue"

    std::fill_n(temp, newCapacity, T());

    if (!isEmpty())
    {
        if (length < newCapacity)
        {
            moveItems(items, temp, length);
            //std::copy_n(&items[front], newCapacity, temp);
        }
        else
        {
            
            moveItems(items, temp, newCapacity);
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
void queue<T>::moveItems(T* origin, T* dest, size_t len)
{
    if (origin == nullptr || dest == nullptr)
        return;

    const bool greater = (length > len); // Is the length greater than what it is trying to move?
                                         // Copying "len" objects from an original array will when the length is less than "len" will lead
                                         // to a loss of objects in the queue.

    if (front > rear) // Did the position of the rear wrap around?
    {
        size_t rearPos = capacity - front;
        
        if (rearPos > capacity)
            return;

        if (greater)
        {
            const size_t f = len - front;
            const size_t difference = length - f;
            const size_t r = (rear - difference);
            
            std::move(&origin[front], &origin[capacity], dest);
            std::move(&origin[0], &origin[rear - r + 1], &dest[rearPos]);
            front = 0, rear = len - 1;
        }
        else
        {
            std::move(&origin[front], &origin[capacity], dest);
            std::move(&origin[0], &origin[rear + 1], &dest[rearPos]);

            front = 0, rear = length - 1;
        }
    }
    else
    {
        if (greater)
        {
            const size_t difference = length - len;
            const size_t r = rear - difference;
            std::move(&origin[front], &origin[rear - r + 1], dest);
            front = 0, rear -= r;
        }
        else
        {
            std::move(&origin[front], &origin[rear + 1], dest);
            front = 0, rear = length - 1;
        }

    }
}

template <class T>
void queue<T>::makeEmpty() // Destroys all the objects in the queue
{
    if (items)
        delete[] items;
    length = 0, capacity = 0, front = 0, rear = -1;
}

template <class T>
T queue<T>::peek()
{
    if (isEmpty())
        return T();
        // throw "attempted to access empty queue"

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
            // throw "cannot reserve more objects for queue"
    }

    if (isFull())
    {
        size_t testCapacity = capacity;

        expand(capacity * GROWTH_FACTOR);

        if (capacity == testCapacity)
            return;
    }

    rear = (rear + 1) % capacity;

    items[rear] = item;

    length++;
}

template <class T>
void queue<T>::dequeue()
{
    if (isEmpty())
        return;

    items[front].~T();
    front = (front + 1) % capacity;
    
    length--;

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
    delete[] items;
}
#endif