// https://www.geeksforgeeks.org/problems/rotation4723/1

// Find index of minimum element
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
       int n=nums.size();

        int start=0;
        int end=n-1;

        int mini=INT_MAX-5;
        while(start<=end){
            int mid=(start+end)/2;

            // sorted
            if(nums[end]>=nums[start]){
                return start;
            }

            if(mid-1>=start && nums[mid]<nums[mid-1]){
                return mid;
            }

            if(nums[mid]<nums[start]){
                // left unsorted
                // minimum in unsorted
                end=mid-1;
            }else if(nums[end]<nums[mid]){
                // right unsorted
                start=mid+1;
            }

        }

        return -1;
    }
};
