// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Distinct elements
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        int mini=INT_MAX-5;
        while(start<=end){
            int mid=(start+end)/2;

            // sorted
            if(nums[end]>=nums[start]){
                return nums[start]; // only for single element
            }


            if(mid+1<=end && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }

            if(mid-1>=start && nums[mid]<nums[mid-1]){
                return nums[mid];
            }

            if(nums[mid]<nums[start]){
                // left unsorted
                // minimum in unsorted
                end=mid-1;
            }else if(nums[end]<nums[mid]){
                // right unsorted
                start=mid+1;
            }else{
                
            }

        }

        return -1;
    }
};