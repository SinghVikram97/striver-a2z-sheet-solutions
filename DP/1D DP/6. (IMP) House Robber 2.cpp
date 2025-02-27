// https://leetcode.com/problems/house-robber-ii/

// Since houses circular first and last are neighbours
// So either we rob first house or rob the last house
// 2 possibilites and return max
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        // since circular we have 2 options
        // array containing first house
        // array containing last house
        // since both can't be robbed together

        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0],nums[1]);
        }

        vector<int> dp1(n);
        vector<int> dp2(n);

        // rob first house
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);

        // go till n-1
        for(int i=2;i<n-1;i++){
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        
        int maxi1=dp1[n-2];

        // rob last house

        dp2[1]=nums[1];
        dp2[2]=max(nums[1],nums[2]);

        for(int i=3;i<n;i++){
            dp2[i]=max(dp2[i-2]+nums[i],dp2[i-1]);
        }

        int maxi2=dp2[n-1];

        return max(maxi1,maxi2);
    }

    
};