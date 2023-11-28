// https://leetcode.com/problems/target-sum/

// can either add +1 or -1 infront of integer
// then calculate target sum

// Recursive
class Solution {
public:
    int helper(int i, int sum, int n,vector<int> &nums, int target){

        if(i==n){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int op1=helper(i+1,sum+nums[i],n,nums,target);
        int op2=helper(i+1,sum-nums[i],n,nums,target);

        return op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(0,0,n,nums,target);
    }
};