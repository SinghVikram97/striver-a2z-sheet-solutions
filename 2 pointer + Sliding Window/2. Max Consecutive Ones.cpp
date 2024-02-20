// https://leetcode.com/problems/max-consecutive-ones-iii/description/
// Same as before if we go above the limit for zeros move left to index just after the 0
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=i;

        int ans=0;
        int currentKCount=0;
        while(i<n && j<n){
            if(nums[j]==1){
                j++;
                ans=max(ans,j-i);
            }else if(nums[j]==0 && currentKCount==k){
                // Move i to after first occurrence of zero
                while(nums[i]!=0){
                    i++;
                }
                i++;
                currentKCount--;
                // this zero will be considered in next iteration
            }else{
                j++;
                ans=max(ans,j-i);
                currentKCount++;
            }
        }
        return ans;
    }
};