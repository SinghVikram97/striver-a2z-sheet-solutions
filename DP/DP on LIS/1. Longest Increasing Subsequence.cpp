// https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// // dp[i] longest increasing subsequence starting at i
// dp[i]=1+max(dp[j]) where j from i+1 to n-1 and nums[j]>nums[i]

// dp[i]=1 ie. number itself

// return max of all dp[i]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);

        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        // calc max
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }

        return maxi;
        
    }
};