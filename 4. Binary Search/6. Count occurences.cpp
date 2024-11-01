// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Find first and last occurence
class Solution {
  public:
    int count(vector<int>& nums, int target) {
       int n=nums.size();

        int s=0;
        int e=n-1;

        int start=-1;
        while(s<=e){
            int m=(s+e)/2;

            if(nums[m]==target){
                start=m;
                e=m-1;
            }else if(nums[m]<target){
                s=m+1;
            }else{
                e=m-1;
            }
        }

        int end=-1;
        s=0;
        e=n-1;
        while(s<=e){
            int m=(s+e)/2;

            if(nums[m]==target){
                end=m;
                s=m+1;
            }else if(nums[m]<target){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        
        if(start==-1){
            return 0;
        }
        return end-start+1;
    }
};