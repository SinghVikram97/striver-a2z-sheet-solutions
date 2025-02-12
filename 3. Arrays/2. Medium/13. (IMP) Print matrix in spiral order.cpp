// https://leetcode.com/problems/spiral-matrix/description/

// Here lowerRow and upperRow can be replaced by topRow and bottom row

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();     

        int lowerRow=0;
        int upperRow=m-1;

        int lowerCol=0;
        int upperCol=n-1;


        vector<int> ans;
        while(lowerRow<=upperRow && lowerCol<=upperCol){
            for(int j=lowerCol;j<=upperCol;j++){
                ans.push_back(matrix[lowerRow][j]);
            }

            lowerRow++;

            if(lowerRow>upperRow){
                break;
            }

            for(int i=lowerRow;i<=upperRow;i++){
                ans.push_back(matrix[i][upperCol]);
            }

            upperCol--;

            if(upperCol<lowerCol){
                break;
            }

            for(int j=upperCol;j>=lowerCol;j--){
                ans.push_back(matrix[upperRow][j]);
            }

            upperRow--;

            if(upperRow<lowerRow){
                break;
            }

            for(int i=upperRow;i>=lowerRow;i--){
                ans.push_back(matrix[i][lowerCol]);
            }

            lowerCol++;

            if(lowerCol>upperCol){
                break;
            }            
        } 

        return ans;
    }
};