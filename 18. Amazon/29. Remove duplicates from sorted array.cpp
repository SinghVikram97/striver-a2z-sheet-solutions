// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int n=nums.size();

        int i=1;
        while(i<n){
            if(nums[i]==nums[i-1]){
                i++;
            }else{
                index++;
                nums[index]=nums[i];
                i++;
            }
        }

        return index+1;
    }
};