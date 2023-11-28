// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int helper(int i, int j , int m, int n,vector<vector<int> > &dp,vector<vector<int> > &obstacleGrid){
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }

        // Obstacle can be at final position as well
        if(obstacleGrid[i][j]==1){
            dp[i][j]=0;
            return dp[i][j];
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        // can move right
        ans+=helper(i,j+1,m,n,dp,obstacleGrid);
        // can move down
        ans+=helper(i+1,j,m,n,dp,obstacleGrid);
        dp[i][j]=ans;
        return ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp,obstacleGrid);
    }
};