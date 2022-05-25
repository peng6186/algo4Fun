/**
 * @file merge-overlapping-intervals.cpp
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

// O(nlogn) time | O(n) space, where n is the # of intervals in our array
vector< vector<int> > mergeOverlappingIntervals(vector<vector<int>> intervals) {

  if ( intervals.size() == 0 ) return {};

  // sort intervals
  vector < vector<int> > sortedIntervals = intervals;
  sort(sortedIntervals.begin(), sortedIntervals.end(), [] ( vector<int> a, vector<int> b ) { return a[0] < b[0]; });

  int curIntervalStart = sortedIntervals[0][0];
  int curIntervalEnd = sortedIntervals[0][1];

  vector < vector<int> > res;
  for ( auto interval: sortedIntervals ) {
    if ( interval[0] <= curIntervalEnd ) {
      curIntervalEnd = max( curIntervalEnd, interval[1] );
    } else {
      vector <int> temp { curIntervalStart, curIntervalEnd };
      res.push_back( temp );
      // reset curInterval
      curIntervalStart = interval[0];
      curIntervalEnd = interval[1];
    }
  }

  // put the last interval into res
  vector<int> temp { curIntervalStart, curIntervalEnd };
  res.push_back( temp );
  return res;
}