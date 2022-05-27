/**
 * @file BST-construction_recursive.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief hacking BST construction (including insert, contain, & remove ) using recursive method
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**


  Write a BST class for a Binary Search Tree. The class should support:
    Inserting values with the insert method.
    Removing values with the remove method; this method should only remove the first instance of a given value.
    Searching for values with the contains method.
 
 *      
 *  Sample Input:
 *   Given a BST: 
         10
       /     \
      5      15
    /   \   /   \
   2     5 13   22
 /           \
1            14

    insert(12):

 *   Sample output: ( insert(12): )
 *            10
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /        /  \
     1        12  14

 */



#include <vector>
using namespace std;

// Using recursive implementation
// Average O(logn) time | O(logn) space (call stack), where n i # of nodes in the BST
// Worst O(n) time | O(n) space (call stack)
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) { // okay
    // Write your code here.
    // Do not edit the return statement of this method.
    if (val < value) { // left subtree
      if (left == nullptr) // find the place
        left = new BST(val);
      else // recursively continue
        left -> insert(val);
    } else { // right subtree
      if (right == nullptr)
        right = new BST(val);
      else
        right -> insert(val);
    }
    return *this;
  }

  bool contains(int val) { // okay
    // Write your code here.
    if (val < value) { // left subtree
      if (left == nullptr)
        return false;
      else 
        return left -> contains(val);
    } else if (val > value) {
      if (right == nullptr) // right substree
        return false;
      else 
        return right -> contains(val);
    } else { // val == value
      return true;
    }
  }

  BST& remove(int val, BST* parentNode = nullptr) {

    if (val < value) { // left subtree
      if (left != nullptr) {
        left -> remove(val, this);
      }
    } else if (val > value) { // right subtree
      if (right != nullptr) {
        right -> remove(val, this);
      }
    } else { // the current Node is the node to be removed
      if (left != nullptr && right != nullptr) { // right subtree and left subtree are not null
        value = right -> getMinVal();
        right -> remove (value, this);
      } else if (parentNode == nullptr) { // parent node doesn't exist (i.e. the node to be removed is root)
        if (left != nullptr) {
          value = left -> value;
          right = left -> right; // we don't wanna contaminate left value here
          left = left -> left;
        } else if (right != nullptr) {
          value = right -> value;
          left = right -> left;
          right = right -> right;
        } else { // only single-node tree, we do nothing
          
        }
      } else if (parentNode -> left == this) { // when the currentNode has a parent
        parentNode -> left = ( left != nullptr? left : right );
      } else if (parentNode -> right == this) {
        parentNode -> right = ( left != nullptr? left : right );
      }
      break;
    }
    return *this;
  }

  // helper method to get the smallest value of the right subtree 
  int getMinVal() {
    if (left == nullptr)
      return value;
    else 
      return left -> getMinVal();
  }
};
