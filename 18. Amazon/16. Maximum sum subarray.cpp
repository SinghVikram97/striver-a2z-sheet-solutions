// https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int cs=0;
        int ms=INT_MIN;

        for(int i=0;i<n;i++){
            cs=max(cs+nums[i], nums[i]);
            ms=max(ms,cs);
        }

        return ms;
    }
};