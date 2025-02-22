// https://leetcode.com/problems/jump-game/description/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int currentIndex=n-1;

        while(currentIndex!=0){
            int nextIndex=-1;
            for(int i=currentIndex-1;i>=0;i--){
                if(nums[i]+i>=currentIndex){
                    nextIndex=i;
                }
            }

            if(nextIndex==-1){
                return false;
            }

            currentIndex=nextIndex;
        }

        return true;
    }
};