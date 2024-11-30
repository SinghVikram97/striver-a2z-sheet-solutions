// https://leetcode.com/problems/binary-subarrays-with-sum/

// Number of subarrays with number of ones equal to goal

// Brute force - TLE
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        int ans=0;
        
        for(int i=0;i<n;i++){
            int oneCount=0;

            for(int j=i;j<n;j++){
                if(nums[j]==1){
                    oneCount++;
                }

                if(oneCount==goal){
                    ans++;
                }
                else if(oneCount>goal){
                    break;
                }
            }
        }

        return ans;
    }
};

// Since it asks for subarray with sum = goal, ie exact 
// We can use same trick of atmost
// atMost(goal)-atMost(goal-1)

// Subarrays with atMost goal number of ones

// Now if a window is valid ie. atMost goal number of ones b/w left and right
// SO every substring ending at right will also be a valid substring
// For example
// 1 0 1 and goal is 2
// and left=0 and right=2
// Now 101 valid , 01 valid and 1 valid so we add right-left+1
class Solution {
public:
    int atMost(vector<int> &nums, int k){
        if(k<0){
            return 0;
        }
        int n=nums.size();

        int left=0;
        int right=0;

        int ans=0;
        int onesCount=0;
        while(left<=right && right<n){
            if(nums[right]==1){
                onesCount++;
            }

            if(onesCount<=k){
                // update ans
                ans+=right-left+1;
                // increase window
                right++;
            }else{
                // >k
                // reduce window
                while(left<=right && onesCount!=k){
                    if(nums[left]==1){
                        onesCount--;
                    }
                    left++;
                }

                if(left>right){
                    // start again where left stops
                    // if left stops at right+1 we start from there
                    // And bring right at right+1
                    right=left;
                }else if(onesCount==k){
                    // Now ones count is equal to k
                    // update ans
                    ans+=right-left+1;
                    // increase window
                    right++;
                }
                
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};