// https://leetcode.com/problems/jump-game-ii/
// Greedy start from last and reach the farthest index which is able to reach last
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        if(n==0 || n==1){
            return 0;
        }

        int lastIndex=n-1;
        int ans=0;
        while(lastIndex!=0){
            int nextIndex=-1;
            for(int i=lastIndex-1;i>=0;i--){
                if(nums[i]+i>=lastIndex){
                    nextIndex=i;
                }
            }

            if(nextIndex==-1){
                return -1;
            }

            lastIndex=nextIndex;
            ans++;
        }
        return ans;
    }
};