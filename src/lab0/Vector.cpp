#include <vector>
#include <iostream>
#include "/mnt/c/Users/User/OOP_MAI/include/Vector.hpp"

template<typename T>
Vector<T>::Vector() = default;

template<typename T> ////////////////////////////////////
// копирование
Vector<T>::Vector(const Vector& other) {
    elements_.reserve(other.elements_.size()); ///////////////////
    for(const auto& element : other.elements_)
        elements_.push_back(std::make_unique<T>(*element));
}
template<typename T>
Vector<T>::Vector(Vector&& other) noexcept { //перемещение
    elements_ = std::move(other.elements_);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) { //присваивание копированием
    if (this != &other) {
        elements_.clear();
        elements_.reserve(other.elements_.size());
        for(const auto& element : other.elements_)
            elements_.push_back(std::make_unique<T>(*element));
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept { //присваивание перемещением
        if (this != &other) {
            elements_ = std::move(other.elements_);
        }
        return *this;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const { //сравнение
    if(elements_.size() != other.elements_.size())
        return false;

    for(size_t i = 0; i < elements_.size(); ++i) {
        if(*elements_[i] != *other.elements_[i])
            return false;
    }
    return true;
}

template<typename T>
Vector<T>::~Vector() {
    for(auto element : elements_)
        delete element;
}

template<typename T>
void Vector<T>::addElement(std::unique_ptr<T> element) {
    elements_.push_back(element); //////////elements_.push_back(std::move(element));
}

template<typename T>
void Vector<T>::deleteElement(int index) {
    if(index >= 0 && index < elements_.size()) {
        delete elements_[index];
        elements_.erase(elements_.begin() + index);
    }
}

template<typename T>
void Vector<T>::printElements() const {
    for(const auto& element : elements_)
        std::cout << *element << std::endl;
}

template<typename T>
int Vector<T>::size() const {
    return elements_.size();
}
