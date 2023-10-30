#include <iostream>
#include <string>
#include "Thirteen.h"

using namespace std;

int main() {
    try {
        string val1, val2;
        cout << "Enter first number: ";
        cin >> val1;
        cout << "Enter second number: ";
        cin >> val2;

        Thirteen num1(val1);
        Thirteen num2(val2);

        char operation;
        cout << "What operation do you want to perform: ";
        cin >> operation;

        switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;

        case '>':
            if (num1 > num2)
                cout << "The first number is greater" << endl;
            else
                cout << "The second number is greater or they are equal" << endl;
            break;

        case '<':
            if (num1 < num2)
                cout << "The first number is smaller" << endl;
            else
                cout << "The second number is smaller or they are equal" << endl;
            break;

        case '=':
            if (num1 == num2)
                cout << "The numbers are equal" << endl;
            else
                cout << "The numbers are not equal" << endl;
            break;

        default:
            cout << "No such operation" << endl;
            break;
        }
    }
    catch (const invalid_argument& ex) {
        cout << "Invalid argument exception caught: " << ex.what() << endl;
    }

    return 0;
}
