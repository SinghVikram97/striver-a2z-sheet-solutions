// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        
        int totalSum=0;
        unordered_set<int> ms;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            ms.insert(nums[i]);
            mp[nums[i]]++;
        }

        int maxi=INT_MIN+5;
        for(int i=0;i<n;i++){
            // consider nums[i] as special num equal to sum
            int tempSum=totalSum-nums[i];

            // now we have to substract a number (outlier) from tempSum so that we get remaining number sum 
            // find if such an outlier exists
            // and if it exists it shouldn't be same as special num so that's why we have mp

            if(ms.find(tempSum-nums[i])!=ms.end()){
                if(nums[i]==tempSum-nums[i] && mp[nums[i]]==1){
                    // outlier = special num not possible 
                }else{
                    maxi=max(maxi, tempSum-nums[i]);
                }
            }
        
        }

        return maxi;
    }
};