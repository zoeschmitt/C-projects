// File Name: StringList.h
// Represents a list of strings.
// Supports adding and removing strings, displaying and searching the list,
// reversing and copying lists, and checking if 2 lists are equal.

#include <string>
using namespace std;

class StringList
{
  public:
    struct StringNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        StringNode *next;      // points to next node in list
    };
    
    StringNode *head;           // the head pointer
    int find(string, bool);

  public:
    StringList();
    ~StringList();
    
    void add(string);
    int findFirst(string);
    int findLast(string);
    bool remove(int);
    void display();
    void reverse();
    StringList copy();
    bool equal(StringList&);
};
