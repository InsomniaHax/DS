#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack()
{
    stackPtr = nullptr;
}

Stack::~Stack()
{
    item* p1;
    item* p2;

    p1 = stackPtr;
    
    while(p1 != nullptr)
    {
        p2 = p1;
        p1 = p1->prev;
        p2->prev = nullptr;
        delete p2;
    }
}

void Stack::Push(string name, int value)
{
    item* n = new item;

    n->name = name;
    n->value = value;

    if(stackPtr == nullptr)
    {
        stackPtr = n;
        stackPtr->prev = nullptr;
    }
    else
    {
        n->prev = stackPtr;
        stackPtr = n;
    }
}

void Stack::ReadItem(item* r)
{
    cout << "--------------------------\n";
    cout << "name: " << r->name << endl;
    cout << "value: " << r->value << endl;
    cout << "--------------------------\n";
}

void Stack::Pop()
{
    if(stackPtr == nullptr)
    {
        cout << "The stack is empty";
    }
    else
    {
        item* p = stackPtr;
        stackPtr = stackPtr->prev;
        p->prev = nullptr;
        delete p;
    }
}

void Stack::Print()
{
    item* p = stackPtr;

    while(p->prev != nullptr)
    {
        ReadItem(p);
        p = p->prev;
    }
}
