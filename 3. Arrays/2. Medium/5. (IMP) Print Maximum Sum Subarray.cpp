class Solution {
public:
    pair<int,int> maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int cs = 0;
        int ms = INT_MIN+5;

        int start;
        int max_start;
        int max_end;

        for(int i=0;i<n;i++){
           // include in prev subarray or start fresh

           if(nums[i]>cs+nums[i]){
            // start fresh
             start=i; // update start
             cs=nums[i];
           }
           else{
            // include in prev
            cs+=nums[i];
           }
           
           if(ms>cs){
             ms=cs;
             max_start=start; // update
             max_end=i;
           }
           
        }
        
        return {max_start,max_end};
    }
};