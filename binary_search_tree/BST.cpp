#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
    if(root == nullptr)
    {
        root = CreateLeaf(key);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left != nullptr)
        {
            AddLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right != nullptr)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        cout << "The key " << key << "has already been added to the tree" << endl;
    }
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
    if(root != nullptr)
    {
        if(Ptr->left != nullptr)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if(Ptr->right != nullptr)
        {
            PrintInOrderPrivate(Ptr->right);
        } 
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
    ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != nullptr)
    {
        if(Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if(key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return nullptr;
    }
}

int BST::ReturnRootKey()
{
    if(root != nullptr)
    {
        return root->key;
    }
    else
    {
        return -1;
    }
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);

    if(Ptr != nullptr)
    {
        cout << "Parent Node = " << Ptr->key << endl;

        Ptr->left == nullptr ?
        cout << "Left Child = nullptr" << endl :
        cout << "Left Child = " << Ptr->left->key << endl;

        Ptr->right == nullptr ?
        cout << "Right Child = nullptr" << endl :
        cout << "Right Child = " << Ptr->right->key << endl;
    }
    else
    {
        cout << "Key " << key << " is not in the tree" << endl;
    }
}

int BST::FindSmallest()
{
    FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if(root == nullptr)
    {
        cout << "The tree is empty" << endl;
        return -1;
    }
    else
    {
        if(Ptr->left != nullptr)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else
        {
            return Ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
    if(root != nullptr)
    {
        if(root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if(key < parent->key && parent->left != nullptr)
            {
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true) :
                RemoveNodePrivate(key, parent->left);
            }
            else if(key > parent->key && parent->right != nullptr)
            {
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false) :
                RemoveNodePrivate(key, parent->right);
            }
            else
            {
                cout << "The key " << key << "was not found in the tree" << endl;
            }
        }
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

void BST::RemoveRootMatch()
{
    if(root != nullptr)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        if(root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            delete delPtr;
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;

        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            delPtr->left = nullptr;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;
            
        }
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key containing " << rootKey << " was overwritten with " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty" << endl;
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if(root != nullptr)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        if(match->left == nullptr && match->right == nullptr)
        {
            delPtr = match;
            left == true ? parent->left = nullptr : parent->right = nullptr;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed" << endl; 
        }
        else if(match->left == nullptr && match->right != nullptr)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed" << endl; 
        }
        else if(match->left != nullptr && match->right == nullptr)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed" << endl; 
        }
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty" << endl;
    }
}

BST::~BST()
{
    RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
    if(Ptr != nullptr)
    {
        if(Ptr->left != nullptr)
        {
            RemoveSubtree(Ptr->left);
        }
        if(Ptr->right != nullptr)
        {
            RemoveSubtree(Ptr->right);
        }
        
        cout << "Deleting node containing key " << Ptr->key << endl;
        delete Ptr;
    }
}