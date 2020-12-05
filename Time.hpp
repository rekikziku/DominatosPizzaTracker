//August 
#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
public:
    Time();
    Time(int h, int m) throw (logic_error);
    static int elapsedMin(Time start, Time end);
    string stringTime();


private:
    int hour, min;

};

Time::Time(): hour(0), min(0) {
  //Post: Creates a time with default values for data members. 
}

Time::Time(int h, int m) throw(logic_error) {
  //Pre: 0 <= hour <= 23 and 0 <= min <= 59.
  //Post: Creates a time with the given hour and minute. 

    hour = h;
    min = m;
}

int Time::elapsedMin(Time start, Time end) {
  //Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1. 
    int totalMin = ((end.hour * 60) + end.min) - ((start.hour * 60) + start.min);
    return totalMin;
}

string Time::stringTime() {
  //Post: Returns a string containing the hour and minute (e.g., “13:01”).   
    if(min < 10) {
        string temp = to_string(hour) + ":0" + to_string(min);
    }
    string temp = to_string(hour) + ':' + to_string(min);
    return temp;
}


#endif
