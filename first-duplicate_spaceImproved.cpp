/**
 * @file first-duplicate_spaceImproved.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief Hacking first-duplicate-value question using space Improved ( i.e. only O(1) ) method
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

// O(n) runtime | O(1) space
// this algorithm uses the fact the input is in the range [1, n]
// very specific, may not appropriate for other problems
// map value to array[value - 1] ( i.e. map a value to its index (zero based) in the array )
int firstDuplicateValue(vector<int> array) 
{
  for (auto value: array) {
    int absValue = abs(value);
    // find the duplicate value
    if ( array[absValue - 1] < 0 )
      return absValue;

    // if not find, change it to negative
    array[absValue - 1] *= -1;
  }

  return -1;
}