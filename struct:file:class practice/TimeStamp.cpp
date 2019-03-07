// File Name: TimeStamp.cpp
//
// Author: Dmytro Katrychuk, Jill Seaman
// Date: 10/13/2018
//
// Represents a time in seconds and manipulates the time using values
// in "mm:ss" format.

#include <string>
using namespace std;
#include "TimeStamp.h"

//******************************************************************
// TimeStamp: constructs a Timestamp given a time in "mm:ss" format
// time: the string value to convert from to get total seconds
//******************************************************************
TimeStamp::TimeStamp(string time) {
    int index = time.find(':');
    int minPart = stoi(time.substr(0, index));
    int secPart = stoi(time.substr(index + 1));
    sec = minPart * 60 + secPart;
}

//******************************************************************
// TimeStamp: constructs a Timestamp, setting the seconds to 0
//******************************************************************
TimeStamp::TimeStamp() {
    sec = 0;
}

//******************************************************************
// TimeStamp: constructs a Timestamp given a number of seconds
// _sec: the initial value for the number of seconds.
//******************************************************************
TimeStamp::TimeStamp(int _sec) {
    sec = _sec;
}

//******************************************************************
// toSeconds: returns the total number of seconds as an integer
//******************************************************************
int TimeStamp::toSeconds() {
    return sec;
}

//******************************************************************
// toSeconds: returns the time stored as a string in "mm:ss" format
//******************************************************************
string TimeStamp::toString() {
    string minPart = to_string(sec / 60);
    string secPart = to_string(sec % 60);
    return  minPart + (sec % 60 < 10? ":0": ":") + secPart;
}

//******************************************************************
// add: increments the number of seconds by the amount of time given
//      in "mm:ss" format
// other: the amount of time to be added to this timestamp
//******************************************************************

void TimeStamp::add(string other) {
    TimeStamp temp(other);
    sec += temp.sec;
    return;
}

//******************************************************************
// add: decrements the number of seconds by the amount of time given
//      in "mm:ss" format
// other: the amount of time to be subtracted from this timestamp
//******************************************************************
void TimeStamp::subtract(string other) {
    TimeStamp temp(other);
    sec -= temp.sec;
    return;
}

//******************************************************************
// greaterThan: compares this time to a time given in "mm:ss" format
// returns: true if this time is greater than (later than) the given
//    time
//******************************************************************
bool TimeStamp::greaterThan ( string b) {
    TimeStamp temp(b);
    return sec > temp.sec;
}

