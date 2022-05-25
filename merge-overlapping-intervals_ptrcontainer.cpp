/**
 * @file merge-overlapping-intervals_ptrcontainer.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

  Write a function that takes in a non-empty array of arbitrary intervals,
  merges any overlapping intervals, and returns the new intervals in no
  particular order.

 *      
 *   Sample Input:
 *     array = [[1, 2], [3, 5], [4, 7], [6, 8], [9, 10]]


 *   Sample output:
 *   [[1, 2], [3, 8], [9, 10]]
 *   // Merge the intervals [3, 5], [4, 7], and [6, 8].
 *   // The intervals could be ordered differently.
 */

#include <vector>
#include <algorithm>
using namespace std;

// O(n) time | O(n) space
// This version will need a ptrArray and then convert ptr to the result array
// Since this version add the ptr first,
// it doesn't need that extra push_back after the for loop

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // if input is empty 
  if ( intervals.size() == 0 ) return {};

 vector < vector<int> > sortedIntervals = intervals;
  sort(sortedIntervals.begin(), sortedIntervals.end(), [] ( vector<int> a, vector<int> b ) { return a[0] < b[0]; });

  vector< vector<int>* > mergedPtr;
  vector<int> *curIntervalPtr = &(sortedIntervals[0]);
  mergedPtr.push_back(curIntervalPtr);

  // create result ptr vector
  for ( auto &interval: sortedIntervals ) {
    if ( interval[0] <= curIntervalPtr -> at(1) ) { // it intervalStart <= currentEnd
      curIntervalPtr -> at(1) = max( interval[1], curIntervalPtr -> at(1) );
    } else {
      curIntervalPtr = &interval;
      mergedPtr.push_back( curIntervalPtr );
    }
  }

  // convert it to vector < vector<int> > container
  vector< vector<int> > res;
  for ( auto ptr: mergedPtr ) {
     res.push_back( *ptr );
  }

  return res;
}