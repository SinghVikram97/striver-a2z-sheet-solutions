// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/


// 2 subsets - a number can either be in one or other subset 2 options
// equal partition so keep track of number of numbers in each partition

// if we know sum1 we can calculate sum2 using total sum
// if we know num1 we can calculate num2 using total elements
// i we would need
class Solution {
public:
    int helper(int i,int sum1,int num1, vector<int> &nums, int &totalSum){
        int n=nums.size();

        if(i==n){
            // number of elements should be equal
            // ie num1=n/2;
            if(num1!=n/2){
                return INT_MAX-5;
            }

            int sum2=totalSum-sum1;
            return abs(sum1-sum2);
        }

        // 2 options
        num1++;
        int op1=helper(i+1,sum1+nums[i],num1,nums,totalSum);

        // other option
        num1--;
        int op2=helper(i+1,sum1,num1,nums,totalSum);

        return min(op1,op2);
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        return helper(0,0,0,nums,totalSum);
    }
};


// DP - Won't work for negative numbers
class Solution {
public:
    int helper(int i,int sum1,int num1, vector<int> &nums, int &totalSum, vector<vector<vector<int> > > &dp){
        int n=nums.size();

        if(i==n){
            // number of elements should be equal
            // ie num1=n/2;
            if(num1!=n/2){
                return INT_MAX-5;
            }

            int sum2=totalSum-sum1;
            return abs(sum1-sum2);
        }

        if(dp[i][num1][sum1]!=-1){
            return dp[i][num1][sum1];
        }

        // 2 options
        num1++;
        int op1=helper(i+1,sum1+nums[i],num1,nums,totalSum,dp);

        // other option
        num1--;
        int op2=helper(i+1,sum1,num1,nums,totalSum,dp);

        int ans= min(op1,op2);
        dp[i][num1][sum1]=ans;
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int n=nums.size();
        // i, num1, sum1
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(n,vector<int>(totalSum,-1)));
        return helper(0,0,0,nums,totalSum,dp);
    }
};


// unordered_map<string,int> 
// string composed of i+sum1+num1
class Solution {
public:
    int helper(int i,int sum1,int num1, vector<int> &nums, int &totalSum, unordered_map<string,int> &dp){
        int n=nums.size();

        if(i==n){
            // number of elements should be equal
            // ie num1=n/2;
            if(num1!=n/2){
                return INT_MAX-5;
            }

            int sum2=totalSum-sum1;
            return abs(sum1-sum2);
        }

        string dpString =to_string(i)+"#"+to_string(sum1)+"#"+to_string(num1);

        auto it = dp.find(dpString);
        if(it!=dp.end()){
            return dp[dpString];
        }

        // 2 options
        num1++;
        int op1=helper(i+1,sum1+nums[i],num1,nums,totalSum,dp);

        // other option
        num1--;
        int op2=helper(i+1,sum1,num1,nums,totalSum,dp);

        int ans= min(op1,op2);
        dp[dpString]=ans;
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        unordered_map<string,int> dp;
        return helper(0,0,0,nums,totalSum,dp);
    }
};