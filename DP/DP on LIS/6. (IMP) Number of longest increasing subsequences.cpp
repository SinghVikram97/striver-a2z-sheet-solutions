// https://leetcode.com/problems/number-of-longest-increasing-subsequence/



class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        // length, number of times it occurs
        vector<pair<int,int> > dp(n);

        for(int i=n-1;i>=0;i--){
            dp[i].first=1;
            dp[i].second=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    // if greater, we found a new greater length subsequence
                    if(1+dp[j].first>dp[i].first){
                        dp[i].first=1+dp[j].first;
                        // number of subsequences
                        // [3,5,7] [3,4,7]
                        // by adding 1 we can have 2 new subsequences
                        dp[i].second=dp[j].second;
                    }else if(1+dp[j].first==dp[i].first){
                        // if equal add to number of possible subsequences
                        dp[i].second+=dp[j].second;
                    }
                }
            }
        }

        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i].first);
        }

        int maxLength=maxi;
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i].first==maxLength){
                ans+=dp[i].second;
            }
        }
        
        return ans;
    }
};