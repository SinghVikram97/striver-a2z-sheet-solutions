//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
// Duplicates
class Solution {
public:
    int binarySearchMin(vector<int> &nums, int i, int j){ 
        // invalid start and end, in that case we would return -1 at the end
        // so we catch it here else just return INT_MAX-5 at the end and remove it
        if(i>j){
            return INT_MAX-5;
        }

        if(i==j){
            return nums[i];
        }

        int start=i;
        int end=j;

        while(start<=end){
            int mid=(start+end)/2;

            // sorted
            if(nums[end]>nums[start]){ 
                return nums[start];
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
                // [1,1,1]
                // nums[mid]==nums[start] or nums[mid]==nums[end] or both
                // [10,1,10,10,10]

                // if nums[mid]==nums[start]
                // is it possible to have a number other than nums[mid] in right part? No
                // numbers stay together
                if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                    // find minimum excluding tha element that is equal will consider as 3rd element in min condition at last
                    int min1=binarySearchMin(nums, start+1, mid-1);
                    int min2=binarySearchMin(nums,mid+1,end-1);
                    return min({min1, min2, nums[mid]});
                }else if(nums[mid]==nums[start]){
                    int min1=binarySearchMin(nums, start+1, mid-1);
                    int min2=binarySearchMin(nums, mid+1, end);
                    return min({min1, min2, nums[mid]});
                }else{
                    int min1=binarySearchMin(nums, start, mid-1);
                    int min2=binarySearchMin(nums, mid+1, end-1);
                    return min({min1, min2, nums[mid]});
                }
            }
        }

        return -1;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();

        return binarySearchMin(nums, 0, n-1);
    }
};