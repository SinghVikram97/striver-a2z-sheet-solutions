// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// For this to happen
// Number of array elements must be odd
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=(start+end)/2;

            bool isSingle=true;
            bool left=false;
            bool right=false;
            if(mid-1>=start && nums[mid-1]==nums[mid]){
                isSingle=false;
                left=true;
            }

            if(mid+1<=end && nums[mid+1]==nums[mid]){
                isSingle=false;
                right=true;
            }

            if(isSingle){
                return nums[mid];
            }else{
                if(left){
                    // left elements size excluding mid and mid-1 as they are equal
                    int lsize=mid-start-1;
                    if(lsize%2!=0){
                        // odd number of elements so single element here
                        end=mid-2;
                    }else{
                        // odd number of elements on right 
                        start=mid+1;
                    }
                }else if(right){
                    int rsize=end-mid-1;
                    if(rsize%2!=0){
                        start=mid+2;
                    }else{
                        end=mid-1;
                    }
                }
            }
        }
        return -1;
    }
};