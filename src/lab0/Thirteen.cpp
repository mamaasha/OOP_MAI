#include <string>
#include <iostream>
#include <algorithm>
#include "Thirteen.h"

using namespace std;

// инициализация
Thirteen::Thirteen() : digits(nullptr), size(0){} 

Thirteen::Thirteen(const string& number) : digits(nullptr), size(0) {
    validateNumber(number); // проверка на намбер
    size = number.length(); 
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
        digits[i] = charToDigit(number[i]); // символ -> значение
}

//копирование
Thirteen::Thirteen(const Thirteen& other) : digits(nullptr), size(other.size) {
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
        digits[i] = other.digits[i];
}

// перемещение
Thirteen::Thirteen(Thirteen&& other) noexcept : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0; 
}

Thirteen::~Thirteen()noexcept{ 
    delete[] digits;
}

void Thirteen::validateNumber(const string& number) {
    if (number.empty() 
        || (number[0] == '0' && number.size() > 1)) //число начинается с нуля
        throw invalid_argument("Invalid number format");
    for (char c : number){
        if (c < '0' || c > 'C' )
            throw invalid_argument("Invalid number format");
    }
}

Thirteen& Thirteen::operator=(const Thirteen& other) {
    if (this == &other)
        return *this; 

    delete[] digits;

    size = other.size;
    digits = new unsigned char[size];

    for (size_t i = 0; i < size; i++)
        digits[i] =  other.digits[i];
    
    return *this;
}

Thirteen& Thirteen::operator=(Thirteen&& other)noexcept {
    if (this == &other) 
        return *this;
    
    delete[] digits;

    digits = other.digits;
    size = other.size;
    other.size = 0;
    other.digits = nullptr;

    return *this;
}

Thirteen Thirteen::operator+(const Thirteen& other)const { 
    size_t maxSize = max(size, other.size);
    size_t minSize = min(size, other.size);
    unsigned char* resultDigits = new unsigned char[maxSize + 1];
    unsigned char transfer = 0;
    size_t i = 0;
    for (; i < minSize; i++) {
        unsigned char sum = digits[i] + other.digits[i] + transfer;
        resultDigits[i] = sum % 13;
        transfer = sum / 13;
    }
    for (; i < maxSize; i++) {
        unsigned char sum = 0;
        if (size < other.size)
            sum = other.digits[i] + transfer;
        else
            sum = digits[i] + transfer;
        resultDigits[i] = sum % 13;
        transfer = sum / 13;
    }
    if (transfer > 0) {
        resultDigits[maxSize] = transfer;
        maxSize++;
    }
    Thirteen result;
    result.digits = resultDigits;
    result.size = maxSize;
    resultDigits = nullptr;
    return result;
}

Thirteen Thirteen::operator-(const Thirteen& other )const {
    if(*this < other)
        throw invalid_argument("You can't subtract a larger number from a smaller one");
    size_t maxSize = max(size, other.size);
    size_t i = 0;
    unsigned char* resultDigits = new unsigned char[maxSize];
    int borrow = 0;
    for(; i < other.size; i++){
        int diff = digits[i] - other.digits[i] - borrow;
        if (diff < 0){
            diff += 13;
            borrow = 1;
        }
        else
            borrow = 0;
        resultDigits[i] = diff;
    }
    for (; i < maxSize; i++) {
        int diff = digits[i] - borrow;
        if (diff < 0){
            diff += 13;
            borrow = 1;
        }
        else
            borrow = 0;
        resultDigits[i] = diff;
    }
    Thirteen result;
    delete[] result.digits;
    result.digits = resultDigits;
    result.size = maxSize;
    return result;
}

bool Thirteen::operator>(const Thirteen& other)const {
    if (size > other.size)
        return true;
    else if (size < other.size)
        return false;
    if (size == other.size)
        return other.size;
    for (size_t i = 0; i < size; i++){
        if(digits[i] > other.digits[i])
            return true;
        else if (digits[i] < other.digits[i])
            return false;
    }
    return false;
}

bool Thirteen::operator<(const Thirteen& other)const {
    return !(*this < other) && !(*this == other);
}

size_t Thirteen::getSize() const {
    return size;
}

unsigned char Thirteen::getDigitAt(size_t index) const {
    if (index >= size)
        throw out_of_range("Invalid index");
    return digits[index];
}

bool Thirteen::operator==(const Thirteen& other) const {
    if (size != other.size)
        return false;

    for (size_t i = 0; i < size; i++) {
        if (digits[i] != other.digits[i])
            return false;
    }

    return true;
}

unsigned char Thirteen::charToDigit(char c) {
    if (isdigit(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

char Thirteen::getDigitToChar(unsigned char digit) const { 
    if (digit < 10)
        return digit + '0';
    else 
        return digit - 10 + 'A';
}

ostream& operator<<(ostream& os, const Thirteen& number) {
    for (int i = number.getSize() - 1; i >= 0; i--)
        os << number.getDigitToChar(number.getDigitAt(i));
    return os;
}
                                                