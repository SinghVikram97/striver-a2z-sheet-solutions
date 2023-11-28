// https://leetcode.com/problems/minimum-falling-path-sum/

// Recursion - TLE
class Solution {
public:

    int help(vector<vector<int>>& matrix, int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MAX-5;
        }

        if(i==m-1){
            return matrix[i][j];
        }

        // 3 options 
        int op1=help(matrix,i+1,j-1,m,n);
        int op2=help(matrix,i+1,j,m,n);
        int op3=help(matrix,i+1,j+1,m,n);

        return matrix[i][j]+min({op1,op2,op3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // can start from any element in first row
        int m=matrix.size();
        int n=matrix[0].size();

        int ans=INT_MAX-5;
        for(int j=0;j<n;j++){
            ans=min(ans,help(matrix,0,j,m,n));
        }
        return ans;
    }
};

// DP Memo - TLE

class Solution {
public:
    int help(vector<vector<int>>& matrix, int i,int j,int m,int n, vector<vector<int> > &dp){
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MAX-5;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==m-1){
            return dp[i][j]=matrix[i][j];
        }
        

        // 3 options 
        int op1=help(matrix,i+1,j-1,m,n,dp);
        int op2=help(matrix,i+1,j,m,n,dp);
        int op3=help(matrix,i+1,j+1,m,n,dp);

        return dp[i][j]=matrix[i][j]+min({op1,op2,op3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // can start from any element in first row
        int m=matrix.size();
        int n=matrix[0].size();

        int ans=INT_MAX-5;

        vector<vector<int> > dp(m,vector<int> (n,-1));
        for(int j=0;j<n;j++){
            ans=min(ans,help(matrix,0,j,m,n,dp));
        }
        return ans;
    }
};

// DP - Accepted
// dp[i][j]=matrix[i][j]+min(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
// base case dp[m-1][j]=matrix[m-1][j] where j=0 to n-1
// ans will be min amount dp[0][j] where j=0 to n-1
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int> > dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }   

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
                if(j-1>=0){
                    op1=dp[i+1][j-1];
                }
                op2=dp[i+1][j];
                if(j+1<n){
                    op3=dp[i+1][j+1];
                }
                dp[i][j]=matrix[i][j]+min({op1,op2,op3});
            }
        }

        int ans=INT_MAX-5;
        for(int i=0;i<n;i++){
            ans=min(dp[0][i],ans);
        }

        return ans;
    }
};