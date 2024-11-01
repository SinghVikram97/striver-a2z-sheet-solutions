// https://leetcode.com/problems/search-insert-position/description/

// Inserted just after floor of the number
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();

        int start=0;
        int end=n-1;

        int floor=-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                floor=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return floor+1;
    }
};