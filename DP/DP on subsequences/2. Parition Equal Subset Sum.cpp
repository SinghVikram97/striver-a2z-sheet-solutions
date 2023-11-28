// https://leetcode.com/problems/partition-equal-subset-sum/
// if odd sum can't partition as odd can't be divided equally
// only for even sum
// calculate total sum of the array
// now we need check if it has subset which has totalSum/2 as its sum
// if yes then then true else false

// Recursion - TLE
class Solution {
public:
    bool helper(int i,int sum, int targetSum,vector<int> &nums){
        int n=nums.size();

        if(sum>targetSum){
            return false;
        }

        if(sum==targetSum){
            return true;
        }

        if(i>=n){
            return false;
        }

        int op1=helper(i+1,sum+nums[i],targetSum,nums);
        int op2=helper(i+1,sum,targetSum,nums);

        return op1 || op2;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        
        if(totalSum%2!=0){
            return false;
        }

        int targetSum=totalSum/2;
        return helper(0,0,targetSum,nums);
    }
};

// Memo - DP
class Solution {
public:
    bool helper(int i,int sum, int targetSum,vector<int> &nums,vector<vector<int> > &dp){
        int n=nums.size();

        if(sum>targetSum){
            return false;
        }

        if(sum==targetSum){
            return true;
        }

        if(i>=n){
            return false;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        int op1=helper(i+1,sum+nums[i],targetSum,nums,dp);
        int op2=helper(i+1,sum,targetSum,nums,dp);

        int ans= op1 || op2;

        dp[i][sum]=ans;

        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        
        if(totalSum%2!=0){
            return false;
        }

        int targetSum=totalSum/2;
        vector<vector<int> > dp(n,vector<int>(targetSum,-1));
        return helper(0,0,targetSum,nums,dp);
    }
};