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

  /* ========================================================================
  Template-based Binary Search Trees
  =========================================================================*/

  /* ======================================================================
  * TEST 1: BST is balanced.
  */

  // Vector containing elements to add
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  // Test the template version of the BST with ints
  BST<int> b1;
  for (int item : v) {

    // The auto type here is the pair of BSTIterator<int>, bool
    auto p = b1.insert(item);

    // Pointer to inserted element
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }

    // Success of insertion
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
  }

  // Now test finding the elements we just put in
  for (int item: v) {
      cout << "Finding " << item << "...." << endl;
      BSTIterator<int> foundIt = b1.find(item);
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

  // This is equivalent to BSTIterator<int> en = b1.end();
  // This is null
  auto en = b1.end();

  //This is equivalent to BST<int>::iterator it = b1.begin();
  auto it = b1.begin();

  // "vit" will be -33, 0, 1, 3, 4
  for(; vit != ven; ++vit) {

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

  /* ======================================================================
  * TEST 2: BST is a Linked List.
  */

  // Vector containing elements to add
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(5);

  // Test the template version of the BST with ints
  BST<int> b2;
  for (int item : v2) {

    // The auto type here is the pair of BSTIterator<int>, bool
    auto p = b2.insert(item);

    // Pointer to inserted element
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }

    // Success of insertion
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
  }

  // Now test finding the elements we just put in
  for (int item: v2) {
      cout << "Finding " << item << "...." << endl;
      BSTIterator<int> foundIt = b2.find(item);
      if (*(foundIt) != item) {
          cout << "incorrect value returned.  Expected iterator pointing to "
               << item << " but found iterator pointing to " << *(foundIt)
               << endl;
          return -1;
      }
      cout << "success!" << endl;
  }

  /* ======================================================================
  * TEST 3: BST is a Linked List.
  */

  // Vector containing elements to add
  vector<int> v3;
  v3.push_back(5);
  v3.push_back(4);
  v3.push_back(3);
  v3.push_back(2);
  v3.push_back(1);

  // Test the template version of the BST with ints
  BST<int> b3;
  for (int item : v3) {

    // The auto type here is the pair of BSTIterator<int>, bool
    auto p = b3.insert(item);

    // Pointer to inserted element
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }

    // Success of insertion
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
  }

  // Now test finding the elements we just put in
  for (int item: v3) {
      cout << "Finding " << item << "...." << endl;
      BSTIterator<int> foundIt = b3.find(item);
      if (*(foundIt) != item) {
          cout << "incorrect value returned.  Expected iterator pointing to "
               << item << " but found iterator pointing to " << *(foundIt)
               << endl;
          return -1;
      }
      cout << "success!" << endl;
  }

  /* ======================================================================
  * TEST 4: BST is complete.
  */

  // Vector containing elements to add
  vector<int> v4;
  v4.push_back(14);
  v4.push_back(9);
  v4.push_back(37);
  v4.push_back(25);
  v4.push_back(142);
  v4.push_back(-25);
  v4.push_back(10);

  // Test the template version of the BST with ints
  BST<int> b4;
  for (int item : v4) {

    // The auto type here is the pair of BSTIterator<int>, bool
    auto p = b4.insert(item);

    // Pointer to inserted element
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }

    // Success of insertion
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
  }

  // Now test finding the elements we just put in
  for (int item: v4) {
      cout << "Finding " << item << "...." << endl;
      BSTIterator<int> foundIt = b4.find(item);
      if (*(foundIt) != item) {
          cout << "incorrect value returned.  Expected iterator pointing to "
               << item << " but found iterator pointing to " << *(foundIt)
               << endl;
          return -1;
      }
      cout << "success!" << endl;
  }

  /* ======================================================================
  * TEST 5: BST is empty.
  */

  // Test the template version of the BST with ints
  BST<int> b5;

  // Check if BST is empty
  if(!b5.empty()) {
          cout << "BST is not empty" << endl;
      return -1;
  }
  else {
      cout << "BST is empty" << endl;
  }

  /* ======================================================================
  * TEST 6: BST is balanced.
  */
  cout << "Test 6: BST is balanced." << endl;

  // Vector containing ints to insert, in order
  vector<int> v6;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  // Create an instance of BST holding int
  BSTInt b6;

  // Add each item into the tree
  for(int item : v6) {
      bool result = b6.insert(item);

      // Unsuccessful insertion, return -1 for failure
      if (!result) {
          cout << "Incorrect bool return value when inserting " << item
               << endl;
          return -1;
      }
  }

  // Test size of balanced BST
  if(b6.size() != v6.size()) {
      cout << "Size is: " << b6.size()
           << " ... which is incorrect." << endl;
      return -1;
  }

  // Test to see if we can find the items that we inserted
  for(int item : v6) {

      // Unable to find item
      if (!b6.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  // Get the height of the BST
  cout << "Height of BST 6: " << b6.height() << endl;

  /* ======================================================================
  * TEST 7: BST is a linked list.
  */
  cout << "Test 7: BST is a linked list." << endl;

  // Create a vector containing elements of increasing values
  vector<int> v7;
  v7.push_back(1);
  v7.push_back(2);
  v7.push_back(3);
  v7.push_back(4);
  v7.push_back(5);

  // Create a BST holding int
  BSTInt b7;

  // Add each item in vector into BST
  for (int item: v7) {
    bool result = b7.insert(item);

    if (!result) {
        cout << "Incorrect bool return value when inserting " << item
             << endl;
        return -1;
    }
  }

  // Test size of balanced BST
  if(b7.size() != v7.size()) {
      cout << "Size is: " << b7.size()
           << " ... which is incorrect." << endl;
      return -1;
  }

  // Test the items that are already in the tree
  for(int item : v7) {
      if (!b7.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  // Get the height of the BST
  cout << "Height of BST 7: " << b7.height() << endl;

  /* ======================================================================
  * TEST 8: BST is a linked list.
  */
  cout << "Test 8: BST is a linked list." << endl;

  // Create a vector containing elements of decreasing values
  vector<int> v8;
  v8.push_back(5);
  v8.push_back(4);
  v8.push_back(3);
  v8.push_back(2);
  v8.push_back(1);

  // Create a BST holding int
  BSTInt b8;

  // Add each item in vector into BST
  for (int item: v8) {
    bool result = b8.insert(item);

    if (!result) {
        cout << "Incorrect bool return value when inserting " << item
             << endl;
        return -1;
    }
  }

  // Test size of balanced BST
  if(b8.size() != v8.size()) {
      cout << "Size is: " << b8.size()
           << " ... which is incorrect." << endl;
      return -1;
  }

  // Test the items that are already in the tree
  for(int item : v8) {
      if (!b8.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  // Get the height of the BST
  cout << "Height of BST 8: " << b8.height() << endl;

  /* ======================================================================
  * TEST 9: BST is complete.
  */
  cout << "Test 9: BST is complete." << endl;

  // Vector containing ints to insert, in order
  vector<int> v9;
  v9.push_back(14);
  v9.push_back(9);
  v9.push_back(37);
  v9.push_back(25);
  v9.push_back(142);
  v9.push_back(-25);
  v9.push_back(10);

  // Create an instance of BST holding int
  BSTInt b9;

  // Add each item into the tree
  for(int item : v9) {
      bool result = b9.insert(item);

      // Unsuccessful insertion, return -1 for failure
      if (!result) {
          cout << "Incorrect bool return value when inserting " << item
               << endl;
          return -1;
      }
  }

  // Test size of balanced BST
  if(b9.size() != v9.size()) {
      cout << "Size is: " << b9.size()
           << " ... which is incorrect." << endl;
      return -1;
  }

  // Test to see if we can find the items that we inserted
  for(int item : v9) {

      // Unable to find item
      if (!b9.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  // Get the height of the BST
  cout << "Height of BST 9: " << b9.height() << endl;


  /* ======================================================================
  * TEST 10: BST is unbalanced.
  */
  cout << "Test 10: Empty BST" << endl;

  // Create an BST
  BSTInt b10;

  // Check if BST is empty
  if(!b10.empty()) {
          cout << "BST is not empty" << endl;
      return -1;
  }
  else {
      cout << "BST is empty" << endl;
  }

  cout << "All tests passed!" << endl;

  return 0;
}
