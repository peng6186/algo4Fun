/**
 * @file first-duplicate_map.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief Hacking first-duplicate-value question using unorded_map method
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
#include <unordered_map>

using namespace std;

// O(n) runtime | O(n) space
int firstDuplicateValue(vector<int> array) 
{ 
  unordered_map<int, bool> seen;
  
  for ( auto value: array) {
    // if find the duplicate value, that also has the min idx
    if ( seen.find(value) != seen.end() ) {
      return value;
    }

    // if not, put this value into our auxilliary map
    seen[value] = true;
  }
  
  return -1;
}
