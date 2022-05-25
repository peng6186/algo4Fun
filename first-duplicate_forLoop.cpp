/**
 * @file first-duplicate_forLoop.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief Hacking first-duplicate-value question using two for loop method
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

  Given an array of integers between 1 and n, where n is the length of the array, write a function
  that returns the first integer that appears more than once (when the array is
  read from left to right).

 *      
 *   Sample Input:
 *     array = [2, 1, 5, 3, 3, 2, 4]

 *   Sample output:
 *   3 
 *   // 3 is the first integer that appears more than once.
 *   // 2 also appears more than once, but the second 2 appears after the second 3.
 */

#include <vector>
#include <algorithm>
using namespace std;

// O(n^2) runtime | O(1) space
int firstDuplicateValue(vector<int> array) 
{ 
  int minSndIdx = array.size(); // set the default value to array's size
  for ( int i = 0; i < array.size(); ++i ) {
    for ( int j = i + 1; j < array.size(); ++j ) {
      if (array[i] == array[j]) // if there's a duplicate
        minSndIdx = min(minSndIdx, j); // store the index
    }
  }

  if ( minSndIdx == array.size() ) return -1;
  return array[minSndIdx]; 
}
