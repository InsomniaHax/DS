#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(/* args */)
{
    nodePtr front = nullptr;
    nodePtr rear = nullptr;
}

Queue::~Queue()
{
    nodePtr delPtr;
    while(front != nullptr)
    {
        delPtr = front;
        front = front->next;
        delPtr->next = nullptr;
        delete delPtr;
    }
}

bool Queue::isempty()
{
    if(front == nullptr && rear == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Queue::enqueue(int value)
{
    nodePtr ptr = new node();
    ptr->data = value;
    ptr->next = nullptr;

    if(front == nullptr)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void Queue::dequeue()
{
    if(isempty())
    {
        cout << "Queue is empty";
    }
    if(front == rear)
    {
        free(front);
        front = rear = nullptr;
    }
    else
    {
        nodePtr ptr = front;
        front = front->next;
        free(ptr);
    }
}

void Queue::showfront()
{
    if(isempty())
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << front->data;
    }
}

void Queue::displayqueue()
{
    if(isempty())
    {
        cout << "Queue is empty";
    }
    else
    {
        nodePtr ptr = front;
        while(ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}
