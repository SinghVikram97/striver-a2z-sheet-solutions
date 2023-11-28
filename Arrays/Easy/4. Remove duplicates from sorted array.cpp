// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int lastPos=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[lastPos]){
                continue;
            }
            lastPos++;
            nums[lastPos]=nums[i];
        }
        return 1+lastPos;
    }
};