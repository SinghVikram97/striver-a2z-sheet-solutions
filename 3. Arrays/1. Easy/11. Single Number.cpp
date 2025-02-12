// https://leetcode.com/problems/single-number/
// XOR:
// 0 0 = 0
// 0 1 = 1
// 1 0 = 1
// 1 1 = 0

// a^a = 0
// a^0 = a


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};