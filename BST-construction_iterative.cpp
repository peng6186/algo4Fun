/**
 * @file BST-construction_iterative.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief 
 * @version 0.1
 * @date 2022-05-27
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

// iterative way to implement it
// Average: O(logn) time | O(1) space , where n is # of nodes in the BST
// Worst: O(n) time | O(1) space
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

  BST& insert(int val) {
    BST *currentNode = this;
    while ( true ) { // we could always find a null node and insert the new node
      if ( val < currentNode -> value ) { // left subtree
          if ( currentNode -> left == nullptr ){
            currentNode -> left = new BST(val); // locate the correct place
            break;
          } else
            currentNode = currentNode -> left;
      } else { // right subtree
          if ( currentNode -> right == nullptr ){
            currentNode -> right = new BST(val);
            break;
          } else
            currentNode = currentNode -> right;
      }
    }
    return *this;
  }

  bool contains(int val) {
    BST *currentNode = this;
    while ( currentNode != nullptr ) {
      if ( val < currentNode -> value ) { // left subtree
          currentNode = currentNode -> left;
      } else if ( val > currentNode -> value ) { // right subtree
          currentNode = currentNode -> right;
      } else { // val == currentNode -> value
        return true;
      }
    }
    return false; 
  }
  BST& remove(int val, BST *parentNode = nullptr) {

    BST *currentNode = this;
    while ( currentNode != nullptr ){
      if ( val < currentNode -> value ) { // left subtree
        parentNode = currentNode;
        currentNode = currentNode -> left;
      } else if ( val > currentNode -> value ) { // right subtree (val > currentNode -> value)
        parentNode = currentNode;
        currentNode = currentNode -> right;
      } else { // currentNode is the node to be removed
        if ( currentNode->left != nullptr && currentNode->right != nullptr ) { // two children are not nullptr
          currentNode -> value = currentNode -> right -> getMinVal();
          currentNode -> right -> remove( currentNode -> value, currentNode );
        } else if ( parentNode == nullptr ) {
          if ( currentNode->left != nullptr ) {
            currentNode->value = currentNode->left -> value;
            currentNode->right = currentNode->left -> right;
            currentNode->left = currentNode->left -> left;
          } else if ( currentNode->right != nullptr ) {
            currentNode->value = currentNode->right -> value;
            currentNode->left = currentNode->right -> left;
            currentNode->right =currentNode->right -> right;
          } else {
            // single-node tree, we do nothing.
          }
        } else if ( parentNode -> left == currentNode ) {
          parentNode -> left = ( currentNode->left != nullptr ? currentNode -> left: currentNode -> right );
        } else if ( parentNode -> right == currentNode ) {
          parentNode -> right = ( currentNode->left != nullptr ? currentNode -> left: currentNode -> right );
        }
        break;
      }
    }
    return *this;
  }

  int getMinVal() {
    if ( left == nullptr ) return value;
    else return left -> getMinVal();
  }
};
