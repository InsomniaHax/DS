#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    struct node 
    {
        int data;
        node* next;
    };
    // Shorthand for node*
    typedef struct node* nodePtr;

    nodePtr front;
    nodePtr rear;

public:
    Queue();
    ~Queue();
    bool isempty();
    void enqueue(int value);
    void dequeue();
    void showfront();
    void displayqueue();
};



#endif