// https://leetcode.com/problems/jump-game/

// Start from last and go to the farthest index from where you can reach current pos
// If able to reach 0 then true else false
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
                return false; // can't reach currentIndex from anywhere
            }

            currentIndex=nextIndex;
        }

        return true;
    }
};