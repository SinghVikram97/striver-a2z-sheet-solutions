// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        if(n<=1){
            return true;
        }
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                count++;
            }
        }
        
        if(count==0){
            return true;
        }
        
        if(count==1){
            return nums[0]>=nums[n-1];
        }
        
        return false;
        
    }
}