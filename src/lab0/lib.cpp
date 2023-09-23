#include "lib.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void ValidateInput(int hour, int minute, const string& period) {
    if (hour < 1 || hour > 12) 
        throw out_of_range ("Invalid hour input");

    if (minute < 0 || minute > 59) 
        throw out_of_range ("Invalid minute input");
    
    if (period != "am" && period != "pm")
        throw invalid_argument ("Invalid period input");
}

string FormatTime(int hour, int minute){
    ostringstream result;
    result << setfill('0') << setw(2) << hour << setw(2) << minute;

    return result.str();
}

string ConvertTo24h(int hour, int minute, const string& period) {
    ValidateInput(hour, minute, period);
    if(hour == 12 && period == "pm")
        hour = 0;
    else if(period == "pm")
        hour += 12;

    return FormatTime(hour, minute);
}
                                                