// https://leetcode.com/problems/subarray-sum-equals-k/description/
// [a,b,c,d,e]

// SubarraySum(c...d)=CurrentSum(a...d)-previousSubrraySum(a..b)

// TargetSum = CurrentSum - previousSubarraySum

// previouSubarraySum = CurrentSum - targetSum

// So we store frequency of how many times we have seen this previousSubarraySum

// Add (0,1) for full subarray

// ie. [1,2,3],,, 6-0(empty array)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // freq map to store freq of currentSum encountered till now
        unordered_map<int,int> myMap;
        myMap[0]=1; // empty subarray with sum zero

        int currentSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            ans+=myMap[currentSum-k];
            myMap[currentSum]++;
        }
        return ans;
    }
};