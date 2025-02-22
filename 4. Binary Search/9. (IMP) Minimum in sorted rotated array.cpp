// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Distinct elements
// 3 cases 
/*
1. Mid is the minimum
2. otherwise minimum lies in unsorted part
*/
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
            if(nums[end]>nums[start]){ // no equal since distinct elements
                return nums[start]; // only for single element
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
                // Don't need this since distinct elements
            }

        }

        return -1;
    }
};