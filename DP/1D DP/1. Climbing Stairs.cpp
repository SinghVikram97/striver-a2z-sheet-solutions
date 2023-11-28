// https://leetcode.com/problems/climbing-stairs/

// dp[i] = steps to reach ith stair

// dp[i]=dp[i-1]+dp[i-2]
// You can take 1 step from i-1th step or 2 steps from i-2th step
// dp[1]=1, dp[0]=1

// Botton up
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;

        if(n==0 || n==1){
            return 1;
        }

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};