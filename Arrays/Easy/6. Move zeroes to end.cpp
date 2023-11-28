// https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastPos = -1;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                lastPos++;
                swap(nums[i],nums[lastPos]);
            }
        }
    
    }
};