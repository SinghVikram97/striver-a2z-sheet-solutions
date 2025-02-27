// https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Top floor is end of the array
// dp[i] is cost to reach ith floor
// we need dp[n]

// dp[0] and dp[1] are 0 since we can start from there
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return cost[0];
        }

        int dp[n+1];

        dp[0]=0;
        dp[1]=0;

        // can reach dp[i] from dp[i-1] or dp[i-2]
        for(int i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }

        return dp[n];
    }
};