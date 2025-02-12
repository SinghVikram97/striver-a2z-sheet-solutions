// https://leetcode.com/problems/set-matrix-zeroes/description/

// Brute force store rows and columns to make 0 
// Extra space of O(m+n)

/*
Use top row and column as storage and take one other variable col0 for column0 since 0,0 will use for rows
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int col0=-1;
        
        // first process first row and column
        for(int i=0;i<m;i++){
            if(mat[i][0]==0){
                col0=0;
            }
        }

        for(int j=0;j<n;j++){
            if(mat[0][j]==0){
                mat[0][0]=0;
            }
        }


        // Now process rest of the matrix
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }

        // Traverse first row and set 0s
        // start from 2nd row since we want data kept in 1st row intact
        for(int i=1;i<m;i++){
            if(mat[i][0]==0){
                // set whole row zero
                for(int j=1;j<n;j++){
                    mat[i][j]=0;
                }
            }
        }


        // Traverse first column and set 0s
        for(int j=1;j<n;j++){
            // note starting from 1
            if(mat[0][j]==0){
                // set whole column 0
                for(int i=1;i<m;i++){
                    mat[i][j]=0;
                }
            }
        }

        // check mat[0][0] for row now
        if(mat[0][0]==0){
            // make full row 0
            for(int j=0;j<n;j++){
                mat[0][j]=0;
            }
        }

        // check col0 now
        if(col0==0){
            // make full column 0
            for(int i=0;i<m;i++){
                mat[i][0]=0;
            }
        }
        
    }
};