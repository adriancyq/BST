
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{

  // First element to insert
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  // Start at root to find where to insert new node
  BSTNodeInt* curr = root;

  // Find the first appropriate null position
  while (curr->left && curr->right) {

    // Go left if current node is greater than element to insert
    if (item < curr->data) {
      curr = curr->left;
    }

    // Go right if current node is less than element to insert 
    else if (curr->data < item) {
      curr = curr->right;
    }

    // Found an element with same value, do not insert
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  // Start looking at root node
  BSTNodeInt* curr = root;

  // Go until we go past a leaf node
  while (curr) {

    // Go right if node is less than desired
    if (curr->data < item) {
      curr = curr->right;
    }

    // Go left if node is greater than desired
    else if (item < curr->data) {
      curr = curr->left;
    }

    // Found desired node
    else {
      return true;
    }
  }
  return false;
}


/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const
{
  return isize;
}


/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  // TODO
  return 0;
}


/** Return true if the BST is empty, else false.
 */
bool BSTInt::empty() const
{
  // TODO
  return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  // TODO
}
