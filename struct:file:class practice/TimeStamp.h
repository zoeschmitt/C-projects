// File Name: TimeStamp.h
//
// Author: Dmytro Katrychuk, Jill Seaman
// Date: 10/13/2018
//
// Represents a time in seconds and manipulates the time using values
// in "mm:ss" format.

#ifndef TIME_STAMP_H
#define TIME_STAMP_H

#include <string>
using namespace std;

class TimeStamp {
private:
    int sec;        // the total number of seconds

public:
    TimeStamp();
    TimeStamp(string time);
    TimeStamp(int _sec);

    int toSeconds();
    string toString();

    void add(string other);
    void subtract(string other);

    bool greaterThan ( string b) ;
};

#endif
