// https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=-1;
        int count=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }
            else{
                maxi=max(maxi,count);
                count=0;
            }
        }
        
        maxi=max(maxi,count);
        return maxi;
    }
};