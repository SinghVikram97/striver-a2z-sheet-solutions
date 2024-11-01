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
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(mid-1>=start && mid+1<=end && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(mid-1>=start && mid+1<=end && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                // like this /
                // move right towards peak
                start=mid+1;
            }else if(mid-1>=start && mid+1<=end && nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                // like this \
                // move left towards peak
                end=mid-1;
            }else if(mid-1>=start && mid+1<=end && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                // like this \/
                // move towards any peak
                start=mid+1;
            }
            else{
                if(mid-1<start && mid+1>end){
                    return mid; // single element
                }else if(mid-1>=start){ 
                    // 2 elements left
                    if(nums[mid-1]>nums[mid]){
                        return mid-1;
                    }else{
                        return mid;
                    }
                }else if(mid+1<=end){
                    if(nums[mid+1]>nums[mid]){
                        return mid+1;
                    }else{
                        return mid;
                    }
                }
            }
        }
        return -1;
    }
};