// https://leetcode.com/problems/minimum-path-sum/

// Recursion
class Solution {
public:
    int helper(vector<vector<int>>& grid, int i,int j, int m,int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MAX;
        }

        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

       
        // can move right
        int op1=helper(grid,i,j+1,m,n);

        // can move down
        int op2=helper(grid,i+1,j,m,n);

        int ans=min(op1,op2);

        return ans+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return helper(grid,0,0,m,n);
    }
};

// DP
class Solution {
public:
    int helper(vector<vector<int>>& grid, int i,int j, int m,int n,vector<vector<int> > &dp){
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==m-1 && j==n-1){
            return dp[i][j]=grid[i][j];
        }
        
       
        // can move right
        int op1=helper(grid,i,j+1,m,n,dp);

        // can move down
        int op2=helper(grid,i+1,j,m,n,dp);

        int ans=min(op1,op2);

        dp[i][j]= ans+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return helper(grid,0,0,m,n,dp);
    }
};