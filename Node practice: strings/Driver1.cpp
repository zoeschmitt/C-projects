//Driver1.cpp: using StringList
// A Simpler test-driver for the StringList

#include <iostream>
#include "StringList.h"

int main() {
    
    // set up the list
    StringList list;
    
    //Add Some values to the list
    list.add("2.5");
    list.add("7.9");
    list.add("12.6");
    list.add("7.9");

    
    // Display the values in the list
    list.display();
    
    // Demo findFirst/findLast:
    cout << "Index of first 7.9: " <<  list.findFirst("7.9") <<endl;
    cout << "Index of last 7.9: " <<  list.findLast("7.9") <<endl;

    // Demo remove:
    cout << endl << "remove 2:" << endl;
    list.remove(2);
    list.display();
    
    cout << endl << "remove 2 again:" << endl;
    list.remove(2);
    list.display();
    
    cout << endl << "remove 0:" << endl;
    list.remove(0);
    list.display();

    cout << endl << "remove 0 again:" << endl;
    list.remove(0);
    list.display();

    StringList list1;
    list1.add("2.5");
    list1.add("7.9");
    list1.add("12.6");
    list1.add("7.9");

    cout << "copy " << endl;
    cout << "original: " << endl;
    list1.display();
    
    cout << "duplicate: " << endl;
    StringList list2 = list1.copy();
    list2.display();
    
    
    cout << "equal  \n";
    StringList listA;
    listA.add("Star Wars");
    listA.add("Titanic");
    listA.add("Back to the Future");
    listA.add("Star Wars");
    
    StringList listB;
    listB.add("Star Wars");
    listB.add("Titanic");
    listB.add("Back to the Future");
    listB.add("Star Wars");
    
    cout << "listA is equal to listB: " << boolalpha << listA.equal(listB) << endl;
    
    listB.add("Raiders of the Lost Ark");
    cout << "listA is equal to listB+RLA: " << listA.equal(listB) << endl;
    cout << "listB+RLA is equal to listA: " << listB.equal(listA) << endl;
    
    listA.add("The Breakfast Club");
    cout << "listA+TBC is equal to listB+RLA: " << listA.equal(listB) << endl;
    
    
    
    //Atest case for reverse
    cout << "reverse" << endl;
    StringList listC;
    listC.add("AAA");
    listC.add("BBB");
    listC.add("CCC");
    listC.add("DDD");
    
    listC.display();
    listC.reverse();
    cout << "------------" << endl;
    listC.display();
}
