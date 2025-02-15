// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        // here we can't discard a negative product because we can have a negative number to the right
        // which will make the product positive

        // so we keep track of both maxTillNow and minTillNow

        int maxTillNow=1;
        int minTillNow=1;
        int finalAns=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                maxTillNow=max(nums[i]*maxTillNow, nums[i]);
                minTillNow=min(nums[i]*minTillNow, nums[i]);
            }else{
                // nums[i]<0 so -*- will give max
                int temp = maxTillNow;
                maxTillNow=max(nums[i]*minTillNow, nums[i]);
                minTillNow=min(nums[i]*temp, nums[i]); // temp since maxTillNow changes
            }
            finalAns=max(finalAns, maxTillNow);
        }

        return finalAns;
    }
};