// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int majorityEle=nums[0];

        int n=nums.size();

        for(int i=1;i<n;i++){
            // Increase count
            if(nums[i]==majorityEle){
                count++;
            }
            else{
                count--;
            }

            // Reset majority element
            if(count==0){
                majorityEle=nums[i];
                count=1;
            }
        }

        if(count>0){
            // exists
            return majorityEle;
        }

        return -1;
    }
};