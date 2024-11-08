// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int i=m-1;
        int j=0;

        while(i>=0 && j<n){
            if(matrix[i][j]==target){
                return true;
            }else if(target>matrix[i][j]){
                // move right
                j++;
            }else{
                // move up
                i--;
            }
        }

        return false;
    }
};