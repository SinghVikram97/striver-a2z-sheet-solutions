// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int cs = 0;
        int ms = INT_MIN+5;

        for(int i=0;i<n;i++){
           // include in prev subarray or start fresh
           cs=max(cs+nums[i],nums[i]);
           ms=max(ms,cs);
        }
        
        return ms;
    }
};