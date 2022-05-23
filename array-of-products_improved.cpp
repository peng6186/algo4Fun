/**
 * @file array-of-products_improved.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief Hacing array-of-products problem using an improved but similiar method
 * @version 0.1
 * @date 2022-05-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

  Write a function that takes in a non-empty array of integers and returns an
  array of the same length, where each element in the output array is equal to
  the product of every other number in the input array.

  In other words, the value at output[i] is equal to the product of
  every number in the input array other than input[i]

 *      
 *   Sample Input:
 *     array = [5, 1, 4, 2]

 *   Sample output:
 *   [8, 40, 10, 20]
 *    // 8 is equal to 1 x 4 x 2
 *    // 40 is equal to 5 x 4 x 2
 *    // ...
 */

#include <vector>

using namespace std;

// O(n) time, O(n) space, where n is # of elements in the array
// we only do 2 loops instead of 3
// we only allocate 1 array to store the result instead of 3

vector<int> arrayOfProducts(vector<int> array) {

  // declare only one vector
  vector<int> products (array.size(), 1);

  // integrate leftProducts into products
  int leftRunningProduct = 1;
  for ( int i = 0; i < array.size(); ++i ) {
    products[i] = leftRunningProduct;
    leftRunningProduct *= array[i];
  }

  // integrate rightProducts into products
  int rightRunningProduct = 1;
  for ( int i = array.size() - 1; i >= 0; --i ) {
    products[i] *= rightRunningProduct;
    rightRunningProduct *= array[i];
  }

  return products;

}