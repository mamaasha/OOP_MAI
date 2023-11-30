#pragma once
#include "/mnt/c/Users/User/OOP_MAI/include/Allocator.h"

template <class T, size_t N, class Alloc = MyAllocator<T, N>>
class MyQueue {
public:
    using value_type = T;
    using allocator_type = Alloc;

private:
    T* data;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;

public:
    MyQueue() : data(allocator_type().allocate(N)), head(0), tail(0), size(0), capacity(N) {}

    ~MyQueue() {
        allocator_type().deallocate(data, capacity);
    }

    void push(const T& value) {
        if (size == capacity) {
            throw std::out_of_range("Queue is full");
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        head = (head + 1) % capacity;
        size--;
    }

    T& front() { // ссылка на голову
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[head];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[head];
    }

    bool empty() const {
        return size == 0;
    }

    std::size_t get_size() {
        return size;
    }
};
