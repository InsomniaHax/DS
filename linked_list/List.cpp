#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

List::List()
{
    head = nullptr;
    curr = nullptr;
    tmp = nullptr;
}

void List::AddNode(int addData)
{
    nodePtr n = new node;

    n->next = nullptr;

    n->data = addData;

    // Checking if we already have a linked list
    if(head != nullptr)
    {
        curr = head;

        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else // else we dont already have a linked list
    {
        // Set the head of the linked list to our newly created node
        head = n;
    }
}

void List::DeleteNode(int delData)
{
    nodePtr delPtr = nullptr;
    tmp = head;
    curr = head;

    // Traverse the linked list till it reaches the end or find a node with delData's value
    while(curr != nullptr && curr->data != delData)
    {
        tmp = curr;
        curr = curr->next;
    }
    if(curr == nullptr)
    {
        cout << delData << " was not in the linked list" << endl;
        delete delPtr;
    }
    else if(curr == head)
    {
        head = head->next;
        tmp = nullptr;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        tmp->next = curr;
        delete delPtr;
        cout << "The value " << delData << "was deleted" << endl;
    }
}

void List::PrintList()
{
    curr = head;
    while(curr->next != nullptr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}