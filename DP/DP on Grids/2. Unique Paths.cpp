// https://leetcode.com/problems/unique-paths/

// Recursion
class Solution {
public:

    void helper(int i, int j , int m, int n, int &ans){
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }

        if(i==m-1 && j==n-1){
            ans++;
            return;
        }

        // can move right
        helper(i,j+1,m,n,ans);
        // can move down
        helper(i+1,j,m,n,ans);
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        helper(0,0,m,n,ans);
        return ans;
    }
};

// Recursion with return
class Solution {
public:
    int helper(int i, int j , int m, int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        int ans=0;
        // can move right
        ans+=helper(i,j+1,m,n);
        // can move down
        ans+=helper(i+1,j,m,n);
        return ans;
    }
    int uniquePaths(int m, int n) {   
        return helper(0,0,m,n);
    }
};

// DP - memo
class Solution {
public:
    int helper(int i, int j , int m, int n,vector<vector<int> > &dp){
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        // can move right
        ans+=helper(i,j+1,m,n,dp);
        // can move down
        ans+=helper(i+1,j,m,n,dp);
        dp[i][j]=ans;
        return ans;
    }
    int uniquePaths(int m, int n) {   
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};