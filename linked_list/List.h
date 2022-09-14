#ifndef LIST_H
#define LIST_H

class List
{
    private:
        struct node
        {
            int data;
            node* next;
        };

        // Shorthand for node*
        typedef struct node* nodePtr;

        nodePtr head;
        nodePtr curr;
        nodePtr tmp;
    
    public:
        List();

        void AddNode(int addData);

        void DeleteNode(int delData);

        void PrintList(); 
};

#endif