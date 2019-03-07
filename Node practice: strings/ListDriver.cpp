// File Name: ListDriver.cpp
// 
// Author: Dmytro Katrychuk, Jill Seaman
// Date: 10/31/2018
// Assignment Number: 5
// CS 2308.003 and 004 Fall 2018
// Instructor: Jill Seaman
//
// A demo driver for StringList.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "StringList.h"

void testEmpty() {
    cout << "------- Test case 1, empty list -------\n";
    //testing StringList
    StringList slist;
    
    // testing on empty list
    cout << "Display:\n";
    slist.display();
    cout << endl;
    
    cout << "Index of first \"empty\": " << slist.findFirst("empty") << endl;
    cout << "Index of last \"empty\": " << slist.findLast("empty") << endl;
    cout << "Try to remove first element: "
    << boolalpha << slist.remove(0) << endl;
    
    cout << "Reversed list: \n";
    slist.reverse();
    slist.display();
    cout << endl;
    
    StringList copied = slist.copy();
    cout << "Copied list: \n";
    copied.display();
    cout << endl;
}

void testSizeOne() {
    cout << "------- Test case 2, list of size 1 -------\n";
    //testing StringList
    StringList slist;
    slist.add("Star Wars");
    
    // testing on empty list
    cout << "Display:\n";
    slist.display();
    cout << endl;
    
    cout << "Index of first \"Star Wars\": " << slist.findFirst("Star Wars") << endl;
    cout << "Index of last \"Star Wars\": " << slist.findLast("Star Wars") << endl;
    cout << "Try to remove first element: "
    << boolalpha << slist.remove(0) << endl;
    
    slist.add("Star Wars");
    
    cout << "Reversed list: \n";
    slist.reverse();
    slist.display();
    cout << endl;
    
    StringList copied = slist.copy();
    cout << "Copied list: \n";
    copied.display();
    cout << endl;
}

void testSizeLong() {
    cout << "------- Test case 3, list of longer size  -------\n";
    //testing StringList
    StringList slist;
    slist.add("Star Wars");
    slist.add("Titanic");
    slist.add("Star Wars");
    slist.add("Back to the Future");
    slist.add("Star Wars");
    
    // testing on empty list
    cout << "Display:\n";
    slist.display();
    cout << endl;
    
    cout << "Index of first \"Star Wars\": " << slist.findFirst("Star Wars") << endl;
    cout << "Index of last \"Star Wars\": " << slist.findLast("Star Wars") << endl;
    cout << "Try to remove last element: "
    << boolalpha << slist.remove(4) << endl;
    
    cout << "Reversed list: \n";
    StringList old = slist.copy();
    slist.reverse();
    slist.display();
    cout << "Old is equal to reversed list: " << old.equal(slist) << endl;
    cout << "Reversed list is equal to old: " << slist.equal(old) << endl;
    cout << endl;
    
    // reverse back and copy
    slist.reverse();
    StringList copied = slist.copy();
    cout << "Copied list: \n";
    copied.display();
    cout << "Copied list is equal to old: " << copied.equal(slist) << endl;
    cout << endl;
}

void testEqual() {
    cout << "------- Test case 4, equal  -------\n";
    //testing StringList
    StringList list1;
    list1.add("Star Wars");
    list1.add("Titanic");
    list1.add("Back to the Future");
    list1.add("Star Wars");
    
    StringList list2;
    list2.add("Star Wars");
    list2.add("Titanic");
    list2.add("Back to the Future");
    list2.add("Star Wars");
    
    cout << "list1 is equal to list2: " << boolalpha << list1.equal(list2) << endl;
    
    list2.add("Raiders of the Lost Ark");
    cout << "list1 is equal to list2+RLA: " << list1.equal(list2) << endl;
    cout << "list2+RLA is equal to list1: " << list2.equal(list1) << endl;
    
    list1.add("The Breakfast Club");
    cout << "list1+TBC is equal to list2+RLA: " << list1.equal(list2) << endl;
}

int main()
{
    testEmpty();
    testSizeOne();
    testSizeLong();
    testEqual();
}

/*
 ------- Test case 1, empty list -------
 Display:
 
 Index of first "empty": -1
 Index of last "empty": -1
 Try to remove first element: false
 Reversed list:
 
 Copied list:
 
 ------- Test case 2, list of size 1 -------
 Display:
 Star Wars
 
 Index of first "Star Wars": 0
 Index of last "Star Wars": 0
 Try to remove first element: true
 Reversed list:
 Star Wars
 
 Copied list:
 Star Wars
 
 ------- Test case 3, list of longer size  -------
 Display:
 Star Wars
 Titanic
 Star Wars
 Back to the Future
 Star Wars
 
 Index of first "Star Wars": 0
 Index of last "Star Wars": 4
 Try to remove last element: true
 Reversed list:
 Back to the Future
 Star Wars
 Titanic
 Star Wars
 Old is equal to reversed list: false
 Reversed list is equal to old: false
 
 Copied list:
 Star Wars
 Titanic
 Star Wars
 Back to the Future
 Copied list is equal to old: true
 
 ------- Test case 4, equal  -------
 list1 is equal to list2: true
 list1 is equal to list2+RLA: false
 list2+RLA is equal to list1: false
 list1+TBC is equal to list2+RLA: false

*/
