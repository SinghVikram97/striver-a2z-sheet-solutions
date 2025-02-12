// https://leetcode.com/problems/search-a-2d-matrix/
// since The first integer of each row is greater than the last integer of the previous row.
// it means we can lay the entire matrix as a 1D array and it will be sorted
// perform binary search then

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int start=0;
        int end=(m*n)-1;

        while(start<=end){
            int mid=(start+end)/2;

            pair<int,int> rowCol=getRowColFromNum(mid, m, n);
            int element = matrix[rowCol.first][rowCol.second];

            if(element==target){
                return true;
            }else if(element<target){
                // move right
                start++;
            }else{
                // move left
                end--;
            }
        }

        return false;
    }

    pair<int,int> getRowColFromNum(int num, int m, int n){
        // 3*4 matrix
        // num: 5
        // rowNo = 5/4 = 1
        // colNo = 5%4 = 1

        // num: 8
        // rowNo = 8/4 = 2
        // colNo = 8%4 = 0

        int rowNo=(num)/n;
        int colNo=(num)%n;

        return {rowNo,colNo};
    }
};