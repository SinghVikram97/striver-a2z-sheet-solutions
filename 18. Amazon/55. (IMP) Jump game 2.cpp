// https://leetcode.com/problems/jump-game-ii/description/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int currentIndex=n-1;
        int jumps=0;

        while(currentIndex!=0){
            int nextIndex=-1;
            for(int i=currentIndex-1;i>=0;i--){
                if(nums[i]+i>=currentIndex){
                    nextIndex=i;
                }
            }

            if(nextIndex==-1){
                return -1; // can't reach currentIndex from anywhere
            }

            jumps++;
            currentIndex=nextIndex;
        }

        return jumps;
    }
};