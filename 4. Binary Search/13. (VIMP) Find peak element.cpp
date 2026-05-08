// https://leetcode.com/problems/find-peak-element/description/

// 4 cases

// mid is peak /\ mid at peak
// mid is / on middle of this
// mid is \ on middle of this
// mid is \/ so move to any of the peak

// so always move towards peak
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(mid-1>=start && mid+1<=end && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(mid-1>=start && mid+1<=end && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                // move right
                start=mid+1;
            }else if(mid-1>=start && mid+1<=end && nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                // move left
                end=mid-1;
            }else if(mid-1>=start && mid+1<=end && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                // move anywhere
                start=mid+1;
            }else{
                // start mid end
                // 2 elements so either start=mid or end=mid
                // start end left basically return max of them
                if(nums[start]>nums[end]){
                    return start;
                }else{
                    return end;
                }
            }
        }

        return -1;
    }
};
