#pragma once
#include <iostream>
#include <map>
#include <vector>

template <class T, size_t N>
class MyAllocator {
public:
    using value_type = T;

    template <class U>
    struct rebind { // переопределяем аллокатор для другого типа
        using other = MyAllocator<U, N>;
    };

    MyAllocator() noexcept {}

    template <class U>
    MyAllocator(const MyAllocator<U, N>&) noexcept {} // копирование по ссылке

    T* allocate(size_t n) { // само выделение памяти
        if (n > N) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, size_t n) noexcept { // освобождение памяти
        if (n > N) {
            throw std::runtime_error("Invalid deallocation size");
        }
        ::operator delete(p);
    }
    // объект типа U на уже выделенной памяти 
    template <typename U, typename... Args> 
    void construct(U* p, Args&&... args) { // указатель на выделенную память, параметры переменнной длины
        new (p) U(std::forward<Args>(args)...); // вызов конструктора типа U на адресе p
    }

    template <typename U>
    void destroy(U* p) {
        p->~U();
    }

    size_t max_size() const { // макс кол-во элементов, которое может быть выделено
        return N;
    }
};
