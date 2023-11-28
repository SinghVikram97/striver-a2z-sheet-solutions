// https://leetcode.com/problems/search-a-2d-matrix-ii/

/*

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

// Different from previous
// Here we can start from rightmost column of first row ( top right )
// if target=element return true
// if target < element we can discard this last column since row sorted from top to bottom, move left
// if target > element we discard this row since this element largest in the row, move down


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int rowNo = 0;
        int colNo = cols-1;

        while(rowNo<rows && colNo>=0){
            int element = matrix[rowNo][colNo];

            if(element==target){
                return true;
            }
            else if(target<element){
                colNo--;
            }
            else{
                rowNo++;
            }
        }
        return false;
    }
};