//
//  BST.h
//  Project4_sorting
//
//  Created by Noah Schlickeisen on 4/22/21.
//  CS 3358 Data Structures and Algorithms (Section 3358-256)
//
//
// This file contains a binary search tree data structure
// it includes methods that opeate on the binary search tree
// these methods include insertion, inorder traversal, removal,
// and searching.
//

#ifndef BST_h
#define BST_h

#include <iostream>

using namespace std;
template <typename T>

class BST
{
private:
    struct BinaryNode
    {
        T value;
        BinaryNode *left;
        BinaryNode *right;
    };
    
    BinaryNode *root;
    bool test = true;
    
    /*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
    Trim (private):
    Recursively goes through each nodee in the tree
    and deallocates the memory.
    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
    void Trim(BinaryNode *nodePtr)
    {
        if (nodePtr)
        {
            Trim(nodePtr->left);
            Trim(nodePtr->right);
            delete nodePtr;
        }
    }
    
    /*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
    NewNode (private):
    Allocates aand returns a node using the binaryNode
    structure. The parameterr is the value that the
    node will hold.
    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
    BinaryNode* newNode(int value)
    {
        BinaryNode* newNode = new BinaryNode();
        
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    
    /*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
    Insert(private):
    Inserts a new node to the appropriate area in
    the binary search tree. The parameters include a BinaryNode
    data type representing the root. The other parameter (value)
    is the value of the new node. This private method returns
    the new node that has been added to the tree.
    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
    BinaryNode* insert(BinaryNode* root, T value)
    {
        // Create new node to add to binary tree
        BinaryNode* newnode = newNode(value);
     
        // Pointer to traverse down tree
        BinaryNode* nodePtr = root;
     
        // Pointer trailing nodePtr
        BinaryNode* preNodePtr = NULL;
        test = true;
        
        while (nodePtr != NULL) {
            preNodePtr = nodePtr;
            // Trverse left if value is less then node value
            if (value < nodePtr->value)
                nodePtr = nodePtr->left;
            // Trverse right if value is greater then node value
            else if (value > nodePtr->value)
                nodePtr = nodePtr->right;
            // return if value already exist
            else
            {
                test = false;
                return nodePtr;
            }
        }
        
        // If the tree is empty
        if (preNodePtr == NULL)
            preNodePtr = newnode;
     
        // Assign to left of last node
        else if (value < preNodePtr->value)
            preNodePtr->left = newnode;
     
        // Assign to right of lest node
        else if (value > preNodePtr->value)
            preNodePtr->right = newnode;
                                 
    
        // Returns the pointer to the inserted node
        return preNodePtr;
    }
    
    
    /*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
    Remove(private):
    This method searches for the new node to be deleted.
    When the new node is deleted, the tree will be resorted
    in its nessesary assortment. The first parameter is a
    node that will traverse the binary tree. The second
    parameter is the value that the node to be deleted will
    hold. This Private function returns the new node to the
    remove public function.
    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
    BinaryNode* remove(BinaryNode* node, int value)
    {
        BinaryNode *nodePtr = node; //
        BinaryNode *preNodePtr = NULL;
        
        test = true;
        
        // Traverse tree to find value
        while (nodePtr != NULL && nodePtr->value != value)
        {
            preNodePtr = nodePtr;
            if (value < nodePtr->value)
                nodePtr = nodePtr->left;
            else if (value > nodePtr->value)
                nodePtr = nodePtr->right;
            
        }
        
        // If the the value is not found
        if (nodePtr == NULL)
        {
            test = false;
            return node; //
        }
        
        // Check if node to delete has no or one child
        if (nodePtr->left == NULL || nodePtr->right == NULL)
        {
            // Create empty node to replace
            BinaryNode *newNode;
            
            if (nodePtr->left == NULL)
                newNode = nodePtr->right;
            else
                newNode = nodePtr->left;
            
            // Check if node to delelete is the root
            if (preNodePtr == NULL)
                return newNode;
            
            // Check if node to delete is previous
            // left or previous right.
            if (nodePtr == preNodePtr->left)
                preNodePtr->left = newNode;
            else
                preNodePtr->right = newNode;
            
            delete newNode;
        }
        
        // If node to be deleted has 2 children
        else
        {
            BinaryNode *preTemp = NULL;
            BinaryNode *temp;
            
            // Find apprpriate replacment
            temp = nodePtr->right;
            while (temp->left != NULL)
            {
                preTemp = temp;
                temp = temp->left;
            }
            
            // Re-assort
            if (preTemp != NULL)
                preTemp->left = temp->right;
            else
                nodePtr->right = temp->right;
            
            nodePtr->value = temp->value;
            
            delete temp; // Free memory
        }
        return node;
    }
    
    
    /*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    InOrder(private):
    Prints traverse the binary search tree using the
    inoder traversal printing valuein incremental order.
    The parameter is a node representing the root.
    \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
    void InOrder(BinaryNode *nodePtr)
    {
        if (nodePtr != NULL)
        {
            InOrder(nodePtr->left);
            cout << (nodePtr)->value << " ";
            InOrder(nodePtr->right);
        }
    }
    
public:
    // Constructor: sets root to NULL
    BST()
    {
        root = NULL;
    }
    
    // Destructor: Recursively emptys treee
    ~BST()
    {
        BinaryNode *nodePtr = nullptr;
        Trim(nodePtr);
    }
    
    bool Insert(const T value);     // inserts value in to tree
    void Print();                   // Prints tree inorder
    bool Contains(const T value) const; //returns true if value in BST
    bool Remove(const T value);     // return true if deletion successful
    
};


/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Print:
Uses Inorderr traversal to print tree
in order.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
void BST<T>::Print()
{
    InOrder(root);
}


/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Insert:
Inserts a new node in to the tree. The value
parmeter is the value thee node will hold.
Returns true if the value is inserted and
false otherwise.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
bool BST<T>::Insert(const T value)
{
    // If tree is empty,set root
    if (root == NULL)
    {
        root = insert(root, value);
        return true;
    }
    insert(root, value);
    return test;
}


/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Remove:
Remove a Node frorm the tree. Returns true
is value removed and false other wise. The
Parmetr is the value that the nodee to be
deleted will hold.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
bool BST<T>::Remove(const T value)
{
    // If tree is empty
    if (root == NULL)
    {
        return false;
    }
    root = remove(root, value);
    return test;
}


/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Contains:
Traverse the list using a given value passed as the
parameter. Once the value is found, return true,
is the value is not foundm return false.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
bool BST<T>::Contains(const T value) const
{
    BinaryNode *nodePtr = root;
    
    // Traverse through tree
    while(nodePtr != NULL)
    {
        // Go left if value is less
        if (value < nodePtr->value)
            nodePtr = nodePtr->left;
        // Go right if value is bigger
        else if (value > nodePtr->value)
            nodePtr = nodePtr->right;
        // If value is found
        else if (value == nodePtr->value)
            return true;
    }
    return false;
}

#endif /* BST_h */
