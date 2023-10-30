#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Thirteen{
public:
    Thirteen();
    Thirteen(const string& number); // инициализация
    Thirteen(const Thirteen& other); // копирование 
    Thirteen(Thirteen&& other)noexcept; // перемещение
    ~Thirteen()noexcept; // деструктор

    Thirteen& operator=(const Thirteen& other); // оператор присваивания
    Thirteen& operator=(Thirteen&& other)noexcept; 

    Thirteen operator+(const Thirteen& other) const;
    Thirteen operator-(const Thirteen& other)const;

    bool operator>(const Thirteen& other)const;
    bool operator<(const Thirteen& other)const;
    bool operator==(const Thirteen& other)const;

    size_t getSize() const;
    unsigned char getDigitAt(size_t index) const;
    char getDigitToChar(unsigned char digit)const;
    friend ostream& operator<<(ostream& os, const Thirteen& number);

private:
    
    unsigned char* digits;
    size_t size; //беззнаковый целочисленнай тип
    void validateNumber(const string& number);
    unsigned char charToDigit(char c); // символ в десятичной в 13
    // char digitToChar(unsigned char digit); // цифру в 13 в символш в 10-ой
};