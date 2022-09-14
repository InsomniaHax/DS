#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H


class hash
{
    private:
        static const int tableSize = 10;

        struct item
        {
            std::string name;
            unsigned int age;
            item* next;
        };

        item* HashTable[tableSize];
        
    public:
        hash();
        int Hash(std::string key);
        void AddItem(std::string name, unsigned int age);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void FindAge(std::string name);
        void RemoveItem(std::string name);
};

#endif