// File Name: StringList.cpp
//
// Author: Zoe Schmitt, Adam Castillio, Eric Figueroa, Julian Sherlock
// Date: 11/11/2018
// Assignment Number: 5
// CS 2308.003 Fall 2018
// Instructor: Jill Seaman
//
// adds and removes strings, displays and searches lists,
// reverses and copys lists, and checks if 2 lists are equal.
#include <string>
#include <iomanip>
#include <iostream>
#include "StringList.h"

//******************************************************************
// StringList: constructs a StringList, setting head to null.
//******************************************************************
StringList::StringList()
{
    head = NULL;
}

//******************************************************************
// ~StringList: creates an empty list, and deallocates all the nodes
// in the list, respectively.
//******************************************************************
StringList::~StringList()
{
    StringNode *p = head;
    while (p!=NULL)
    {
        StringNode *n = p->next;
        delete p;
        p = n;
    }
}

//******************************************************************
// add: adds a new node containing str to the end of the list.
// str is the string from the driver file.
//******************************************************************
void StringList::add(string str)
{
    StringNode *newNode = new StringNode;
    newNode->data = str;
    newNode->next = NULL;
    StringNode *p = head;
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next=newNode;
}

//******************************************************************
// findFirst: finds the index of the first node which contains the
// string str.
// str is the string from the driver file.
// returns the index of the first node which contains the string str.
//******************************************************************
int StringList::findFirst(string str)
{
    StringNode *p = head;
    int indexCount = 0;             //counter for string location.
    
    while (p != NULL)
    {
        
        
        if (p->data == str)
        {
            return indexCount;
        }
        p = p->next;
        indexCount++;
    }
    indexCount = -1;
    return indexCount;
}

//******************************************************************
// findLast: finds the index of the last node which contains the string
// str.
// str is the string from the driver file.
// returns the index of the last node which contains the string str.
//******************************************************************
int StringList::findLast(string str)
{
    StringNode *p = head;
    int indexCount = 0;                     //counter for string location.
    int indexLast = 0;                      //holds location of string.
    bool found = false;
    
    while (p != NULL)
    {
        if (p->data == str)
        {
            indexLast = indexCount;
            found = true;
        }
        p = p->next;
        indexCount++;
    }
    if (found == true)
        return indexLast;
    else {
        indexCount = -1;
        return indexCount;
    }
}

//******************************************************************
// remove: removes the node at the given position from the linked list.
// position is the position of the node to be removed.
// returns true or false depending if it is removed.
//******************************************************************
bool StringList::remove(int position)
{
    if (head == NULL)
        return false;
    
    int indexCount = 0;                     //counter for index position.
    StringNode *p = head;
    StringNode *n = NULL;
    
    while (p != NULL && indexCount != position)
    {
        n = p;
        p = p->next;
        indexCount++;
    }
    
    if (indexCount == position)
    {
        
        if (p == head)
        {
            head = p->next;
            delete p;
        }
        else
        {
            n->next = p->next;
            delete p;
        }
        return true;
    }
    else
    {
        return false;
    }
}

//******************************************************************
// display: displays the strings in the list to the screen, one
// string per line.
//******************************************************************
void StringList::display()
{
    StringNode *p = head;
    
    while (p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    cout << endl;
}

//******************************************************************
// reverse: reverses the order of the values in the stringList.
//******************************************************************
void StringList::reverse()
{
    StringNode *pre = NULL;
    StringNode *p=head;
    StringNode *n;
    
    while (p != NULL)
    {
        n = p->next;
        p->next = pre;
        head = p;
        pre = p;
        p = n;
    }
}

//******************************************************************
// copy: duplicates stringList.
// returns the copy of stringList.
//******************************************************************
StringList StringList::copy()
{
    StringList *other = new StringList;
    StringNode *p = head;
    while (p!=NULL)
    {
        other->add(p->data);
        p = p->next;
        
    }
    return *other;
}

//******************************************************************
// equal: checks if two lists are equal.
// other is the list to be compared.
// returns true or false depending on if the lists were the same or not.
//******************************************************************
bool StringList::equal(StringList &other)
{
    StringNode *p = head;
    StringNode *q = other.head;
    
    while (p!= NULL && q!= NULL)
    {
        if (p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->next;
        
    }
    if (q == NULL && p == NULL)
        return true;
    
    return false;
}
