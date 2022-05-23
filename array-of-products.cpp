/**
 * @file array-of-products.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief Hacing array-of-products problem
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


// O(n) run time, O(n) space 

#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {

  // declare three vectors
  vector<int> products (array.size(), 1);
  vector<int> leftProducts (array.size(), 1);
  vector<int> rightProducts (array.size(), 1);

  // fill in leftProducts
  int leftRunningProduct = 1;
  for ( int i = 0; i < array.size(); ++i ) {
    leftProducts[i] = leftRunningProduct;
    leftRunningProduct *= array[i];
  }

  // fill in rightProducts
  int rightRunningProduct = 1;
  for ( int i = array.size() - 1; i >= 0; --i ) {
    rightProducts[i] = rightRunningProduct;
    rightRunningProduct *= array[i];
  }

  // fill out products
  for ( int i = 0; i < array.size(); ++i ) {
    products[i] = leftProducts[i] * rightProducts[i];
  }

  return products;

}
