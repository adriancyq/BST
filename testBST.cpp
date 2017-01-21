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
 * A test driver for the BST int class and class template. Each test checks
 * insert, size, find, and height.
 *
 * PA1 CSE 100 2017
 * Author: Christine Alvarado, Jonathan Chiu, Adrian Cordova
 */
int main() {

    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    // Test the template version of the BST  with ints
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got "
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;

    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt)
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal

    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    // This is null
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();

    // "vit" will be -33, 0, 1, 3, 4
    for(; vit != ven; ++vit) {

        // TODO segfault from dereferencing a null pointer "it"
        // Iterate through the BST's nodes until we hit the end (null)
        if(! (it != en) ) {
            cout << *it << "," << *vit
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    /* ======================================================================
* TEST 1: BST is balanced.
*/
cout << "Test 1: BST is balanced." << endl;

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
if(b.size() != v.size()) {
    cout << "Size is: " << b.size()
         << " ... which is incorrect." << endl;
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

/* ======================================================================
* TEST 2: BST is a linked list.
*/
cout << "Test 2: BST is a linked list." << endl;

// Create a vector containing elements of increasing values
vector<int> v2;
v2.push_back(1);
v2.push_back(2);
v2.push_back(3);
v2.push_back(4);
v2.push_back(5);

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

// Test size of balanced BST
if(b2.size() != v2.size()) {
    cout << "Size is: " << b2.size()
         << " ... which is incorrect." << endl;
    return -1;
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

/* ======================================================================
* TEST 2: BST is a linked list.
*/
cout << "Test 3: BST is a linked list." << endl;

// Create a vector containing elements of decreasing values
vector<int> v3;
v3.push_back(5);
v3.push_back(4);
v3.push_back(3);
v3.push_back(2);
v3.push_back(1);

// Create a BST holding int
BSTInt b3;

// Add each item in vector into BST
for (int item: v3) {
  bool result = b3.insert(item);

  if (!result) {
      cout << "Incorrect bool return value when inserting " << item
           << endl;
      return -1;
  }
}

// Test size of balanced BST
if(b2.size() != v3.size()) {
    cout << "Size is: " << b3.size()
         << " ... which is incorrect." << endl;
    return -1;
}

// Test the items that are already in the tree
for(int item : v3) {
    if (!b3.find(item)) {
        cout << "Incorrect return value when finding " << item << endl;
        return -1;
    }
}

// Get the height of the BST
cout << "Height of BST 3: " << b3.height() << endl;

/* ======================================================================
* TEST 4: BST is unbalanced.
*/
cout << "Test 4: BST is unbalanced." << endl;

// Vector containing ints to insert, in order
vector<int> v4;
v4.push_back(14);
v4.push_back(9);
v4.push_back(37);
v4.push_back(142);
v4.push_back(-25);

// Create an instance of BST holding int
BSTInt b4;

// Add each item into the tree
for(int item : v4) {
    bool result = b4.insert(item);

    // Unsuccessful insertion, return -1 for failure
    if (!result) {
        cout << "Incorrect bool return value when inserting " << item
             << endl;
        return -1;
    }
}

// Test size of balanced BST
if(b4.size() != v4.size()) {
    cout << "Size is: " << b4.size()
         << " ... which is incorrect." << endl;
    return -1;
}

// Test to see if we can find the items that we inserted
for(int item : v4) {

    // Unable to find item
    if (!b4.find(item)) {
        cout << "Incorrect return value when finding " << item << endl;
        return -1;
    }
}

// Get the height of the BST
cout << "Height of BST 4: " << b4.height() << endl;


//Testing empty method
cout << "Test 5: Checking if the BST is empty." << endl;

// Create an BST
BSTInt b5;

//check if BST is empty
if(!b5.empty()){
        cout << "BST is not empty" << endl;
    return -1;
}
else {
    cout << "BST is empty" << endl;
}

cout << "All tests passed!" << endl;

    return 0;
}
