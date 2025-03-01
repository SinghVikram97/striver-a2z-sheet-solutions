// https://leetcode.com/problems/jump-game/

// Recursive
class Solution {
public:
    bool help(vector<int> &nums, int index){
        int n=nums.size();

        if(index==n-1){
            return true;
        }

        if(index>n-1){
            return false;
        }

        int jumpLength=nums[index];

        // can take a jump from 1 to jumpLength
        for(int i=1;i<=jumpLength;i++){
            if(help(nums,index+i)){
                return true;
            }
        }

        return false;
    }
    bool canJump(vector<int>& nums) {
        return help(nums,0);
    }
};

// DP
class Solution {
public:
    bool help(vector<int> &nums, int index, vector<int> &dp){
        int n=nums.size();

        if(index==n-1){
            return true;
        }

        if(index>n-1){
            return false;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int jumpLength=nums[index];

        // can take a jump from 1 to jumpLength
        for(int i=1;i<=jumpLength;i++){
            if(help(nums,index+i,dp)){
                return dp[index]=true;
            }
        }

        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+5,-1);
        return help(nums,0,dp);
    }
};

// Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int currentIndex=n-1;

        while(currentIndex!=0){
            int nextIndex=-1;
            for(int i=currentIndex-1;i>=0;i--){
                if(nums[i]+i>=currentIndex){
                    nextIndex=i;
                }
            }

            if(nextIndex==-1){
                return false;
            }

            currentIndex=nextIndex;
        }

        return true;
    }
};