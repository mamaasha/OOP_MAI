#include <iostream>
#include <string>

#include "lib.h"

using namespace std;
                                                                                                                   

int main(){
    int hour, minute;
    string period;

    cout << "Enter hour(1 - 12): ";
    cin >> hour;

    cout << "Enter minute(0 - 59): ";
    cin >> minute; 

    cout << "Enter period(am/pm): ";
    cin >> period; 

    string ConvertTime = ConvertTo24h(hour, minute, period);

    cout << "Convert to 24-hour format time: " <<  ConvertTime << endl;
    
    return 0;
}