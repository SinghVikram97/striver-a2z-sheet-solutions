// https://leetcode.com/problems/triangle/

// Recursive - TLE
class Solution {
public:
    int help(int i,int j, vector<vector<int> > &triangle){
        int m=triangle.size();
        if(i<0 || i>=m){
            return INT_MAX-5;
        }

        int n=triangle[i].size();
        if(j<0 || j>=n){
            return INT_MAX-5;
        }

        // if we reach last row
        if(i==m-1){
            return triangle[i][j];
        }

        // can move to j or j+1 on next row
        int op1=help(i+1,j,triangle);
        int op2=help(i+1,j+1,triangle);

        int ans=triangle[i][j]+min(op1,op2);
        return ans;

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return help(0,0,triangle);
    }
};

// DP-Memo - Accepted - O(m*n) space
class Solution {
public:
    int help(int i,int j, vector<vector<int> > &triangle, vector<vector<int>>& dp){
        int m=triangle.size();
        if(i<0 || i>=m){
            return INT_MAX-5;
        }

        int n=triangle[i].size();
        if(j<0 || j>=n){
            return INT_MAX-5;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if we reach last row
        if(i==m-1){
            return dp[i][j]=triangle[i][j];
        }

        // can move to j or j+1 on next row
        int op1=help(i+1,j,triangle,dp);
        int op2=help(i+1,j+1,triangle,dp);

        int ans=triangle[i][j]+min(op1,op2);
        dp[i][j]=ans;
        return ans;
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp=triangle;
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=-1;
            }
        }
        return help(0,0,triangle,dp);
    }
};

// Bottom Up DP - BASE CASE will be opposite of top down
// dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])
// dp[m-1][j] = triangle[m-1][j] // last row
// we go upwards till single element

// at ith row there will be i columns
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int> > dp=triangle;
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                dp[i][j]=-1;
            }
        }

        for(int j=0;j<=m-1;j++){
            dp[m-1][j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            // in each row column = row no
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// O(N) Space Optimization
// notice how dp[i][j] only needs data from dp[i+1] ie. next row 
// so we only need 2 row, one below row and one curent row which we fill using below row
// after that current row becomes below row
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> belowRow(m,0);
        vector<int> currentRow(m,0);
     
        for(int i=0;i<=m-1;i++){
            belowRow[i]=triangle[m-1][i];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                currentRow[j]=triangle[i][j]+min(belowRow[j],belowRow[j+1]);
            }
            belowRow=currentRow;
        }
        return belowRow[0];
    }
};