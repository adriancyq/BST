#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Author: Christine Alvarado, Jonathan Chiu, Adrian Cordova
 */
int main() {

    /* TEST 1: BST is balanced */
    cout << "Test 1: Balanced BST." << endl;

    // Vector containing ints to insert, in order
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    // Create an instance of BST holding int
    BSTInt b;

    // Add each item into the tree
    for(int item : v) {
        bool result = b.insert(item);

        // Unsuccessful insertion, return -1 for failure
        if (!result) {
            cout << "Incorrect bool return value when inserting " << item
                 << endl;
            return -1;
        }
    }

    // Test size of balanced BST
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    // Test to see if we can find the items that we inserted
    for(int item : v) {

        // Unable to find item
        if (!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // Get the height of the BST
    cout << "Height of BST 1: " << b.height() << endl;


    /* TEST 2: BST is a linked list. */
    cout << "Test 2: BST is a linked list." << endl;

    // Create a vector containing elements of increasing values
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    // Create a BST holding int
    BSTInt b2;

    // Add each item in vector into BST
    for (int item: v2) {
      bool result = b2.insert(item);

      if (!result) {
          cout << "Incorrect bool return value when inserting " << item
               << endl;
          return -1;
      }
    }

    // Test the items that are already in the tree
    for(int item : v2) {
        if (!b2.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // Get the height of the BST
    cout << "Height of BST 2: " << b2.height() << endl;





    cout << "All tests passed!" << endl;
    return 0;
}
