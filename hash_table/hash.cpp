#include "hash.h"

using std::cout;
using std::endl;

hash::hash()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->age = 0;
        HashTable[i]->next = nullptr;
    }
}

void hash::AddItem(std::string name, unsigned int age)
{
    int index = Hash(name);
    
    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->age = age;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->age = age;
        n->next = nullptr;
        while(Ptr->next != nullptr)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    if(HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != nullptr)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "--------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->age << endl;
        cout << "# of items = " << number << endl;
        cout << "--------------------\n";
    } 
}

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    if(Ptr->name == "empty")
    {
        cout << "index = " << index << " is empty" << endl;
    }
    else
    {
        cout << "index " << index << "contains the following items:\n";
        while(Ptr->next != nullptr)
        {
            cout << "--------------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->age << endl;
            cout << "--------------------\n";
            Ptr = Ptr->next;
        }
    }
}

void hash::FindAge(std::string name)
{
    int index = Hash(name);
    bool foundName = false;
    int age;
    
    item* Ptr = HashTable[index];
    while(Ptr != nullptr)
    {
        if(Ptr->name == name)
        {
            foundName = true;
            age = Ptr->age;
        }
        Ptr = Ptr->next;
    }
    if(foundName)
    {
        cout << "Age = " << age << endl;
    }
    else
    {
        cout << name << "'s info was not found in the hash table" << endl;
    }
}

void hash::RemoveItem(std::string name)
{
    int index = Hash(name);
    item* delPtr = HashTable[index];
    item* P1;
    item* P2;

    if(HashTable[index]->name == "empty" && HashTable[index]->age == 0)
    {
        cout << name << " was not found in the hash table" << endl;
    }
    else if(HashTable[index]->name == name && HashTable[index]->next == nullptr)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->age = 0;
    }
    else if(HashTable[index]->name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        cout << name << " was removed from the hash table" << endl;
    }
    else
    {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while(P1 != nullptr && P1->name != name)
        {
            P2 = P1;
            P1 = P1->next;
        }

        if(P1 == nullptr)
        {
            cout << name << " was not found in the hash table" << endl;
        }
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            cout << name << " was removed from the hash table" << endl;
        }
    }
}

int hash::Hash(std::string key)
{
    int hash = 0;
    int index;
    
    index = key.length();
    
    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) * 19;
    }

    index = hash % tableSize;

    return index; 
}