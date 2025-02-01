// https://leetcode.com/problems/search-a-2d-matrix/
// since The first integer of each row is greater than the last integer of the previous row.
// it means we can lay the entire matrix as a 1D array and it will be sorted
// perform binary search then

// B

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = (rows*cols)-1;

        while(start<=end){

            int mid = (start+end)/2;

            pair<int,int> rowCol = rowColFromNum(rows, cols, mid);
            int element = matrix[rowCol.first][rowCol.second];
            
            if(element==target){
                return true;
            }
            else if(target<element){
                // move left
                end--;
            }
            else{
                start++;
            }
        }

        return false;
    }

    pair<int,int> rowColFromNum(int rows,int cols, int num){
        // 3*4 matrix
        // num: 5
        // rowNo = 5/4 = 1
        // colNo = 5%4 = 1

        // num: 8
        // rowNo = 8/4 = 2
        // colNo = 8%4 = 0

        int rowNo = num / cols;
        int colNo = num % cols;

        return {rowNo, colNo};
    }
};
