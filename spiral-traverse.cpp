/**
 * @file spiral-traverse.cpp
 * @author Peng (pengcheng.xu@tufts.edu)
 * @brief hacking spiral-traverse problem
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**

  Write a function that takes in an n x m two-dimensional array (that can be
  square-shaped when n == m) and returns a one-dimensional array of all the
  array's elements in spiral order.


  Spiral order starts at the top left corner of the two-dimensional array, goes
  to the right, and proceeds in a spiral pattern all the way until every element
  has been visited.

 *      
 *   Sample Input:
 *     array =  = [
                    [1,   2,  3, 4],
                    [12, 13, 14, 5],
                    [11, 16, 15, 6],
                    [10,  9,  8, 7],
                  ]

 *   Sample output:
 *   [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
 */





// O(n) time | O(n) space - where n is the number of elements in the array
#include <vector>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  // result container
  vector<int> res = {};
	
	int startRow = 0, startCol = 0;
	int endRow = array.size() - 1, endCol = array[0].size() - 1;
	
	// the condition when we need to continue
	while ( startRow <= endRow && startCol <= endCol ) {
		// going through the row from left to right
		for ( int col = startCol; col <= endCol; ++col ) {
			res.push_back( array[startRow][col] );
		}
		
		// going through the col from top to bottom
		for ( int row = startRow + 1; row <= endRow; ++row ) {
			res.push_back( array[row][endCol] );
		}
		
		// going back through the row from right to left
		for ( int col = endCol - 1; col >= startCol; --col ) {
			// check if we go through the same row
			// if yes, we don't need to go through them again,
			// which are already been added to res in the 1st for loop.
			if ( startRow == endRow ) break;
			res.push_back( array[endRow][col] );
		}
		
		// going back through the col from bottom to top
		for ( int row = endRow - 1; row > startRow; --row ) {
			// check if we go through the same col
			// if yes, we don't need to go through them again,
			// which are already been added to res in the 2nd for loop.
			if ( startCol == endCol ) break;
			res.push_back( array[row][startCol] );
		}
		
		// update the indices inward
		startRow++;
		startCol++;
		endRow--;
		endCol--;
	}
	return res;
}