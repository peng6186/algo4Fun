/**
 * @file monotonic-array.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief hacking monotonic-array problem
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 
 *   Write a function that takes in an array of integers and returns a boolean
 *   representing whether the array is monotonic.
 *      
 *   Sample Input:
 *     array = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]
 *   Sample output:
 *     true
 */

// -----------------------------------------------------
//  we initialize "is_non_decreasing" and "is_non_increasing" to true, 
//  if the array is not monotonic, both vars must turn to false.
//
//  runtime O(n), space O(1)
// -----------------------------------------------------

#include <vector>

using namespace std;

bool isMonotonic ( vector<int> array ) 
{

    bool is_non_decreasing = true;
    bool is_non_increasing = true;

    for ( int i = 1; i < array.size(); ++i ) {
        if ( array[i] < array[i-1] ) {
            is_non_decreasing = false;
        } else if ( array[i] > array[i-1] ) {
            is_non_increasing = false;
        }
    }

    return is_non_decreasing || is_non_increasing;

}