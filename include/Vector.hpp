#pragma once 

#include <vector>
#include <iostream>
#include <memory>

template<typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector() = default;

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    bool operator==(const Vector& other) const;

    void addElement(std::unique_ptr<T> element);
    void deleteElement(int index);
    void printElements() const;
    int size() const;


private:
    vector<std::unique_ptr<T>> elements_;
};