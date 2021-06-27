
// This driver file runs the test on BST.h using a
// random array.
//

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
// IMPOTANT MESSAGE: When compiling the program on Texas State school
// servers type in command//
//
//                  g++ Assign2_Q2.cpp -std=c++11
//                  ./a.out
//
// This will run the orject on the latest version of C++ to make the program
// effectively.
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BST<int> bnt;
    
    int size = 10;
    bool testValid;
    
    int test4[size];
    
    // Test the the binary array using a random array
    srand(time(NULL));
    int random;
    
    for(int i = 0; i < size; i++)
    {
        random = 0 + rand() % (9);
        test4[i] = random;
    }
    
    // Test Insertion
    cout << "Inserting..." << endl;
    // Testing random array of integers
    for (int i = 0; i < size; i++)
    {
        cout << "Inserting integer " << test4[i] << "  ";
        testValid = bnt.Insert(test4[i]);
        cout << "Return is " << testValid << "  " << endl;
    }
    
    // Test traversal
    cout << endl;
    cout << "Inorder list: ";
    bnt.Print();
    
    // Test Search
    cout << endl << endl;
    cout << "Searching..." << endl;
    for (int i = 0; i < size; i++)
    {
        if (i == 5)
        {
            cout << "Searching integer " << 80 << "  ";
            testValid = bnt.Contains(80);
            cout << "Return is " << testValid << "  " << endl;
        }
        cout << "Searching integer " << test4[i] << "  ";
        testValid = bnt.Contains(test4[i]);
        cout << "Return is " << testValid << "  " << endl;
    }
    
    // Test removal
    cout << endl << endl;
    cout << "Removing..." << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Deleting integer " << i << "  ";
        testValid = bnt.Remove(i);
        cout << "Return is " << testValid << "  " << endl;
    }
    cout << endl;
    cout << "Inorder list: ";
    bnt.Print();
}
