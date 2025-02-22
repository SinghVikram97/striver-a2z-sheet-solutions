// https://leetcode.com/problems/3sum/description/

// Duplicate handling
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n=nums.size();

        vector<vector<int> > ans;
        int targetSum=0;

        for(int i=0;i<n;i++){
            int curEle=nums[i];
            int newTarget=targetSum-curEle;

            int start=i+1;
            int end=n-1;

            while(start<end){
                int sum=nums[start]+nums[end];

                if(sum==newTarget){
                    ans.push_back({curEle, nums[start], nums[end]});
                    
                    // Skip duplicates
                    int curStart=nums[start];
                    while(start<end && nums[start]==curStart){
                        start++;
                    }

                    int curEnd=nums[end];
                    while(start<end && nums[end]==curEnd){
                        end--;
                    }

                    if(start>=end){
                        break;
                    }

                }else if(sum<newTarget){
                    start++;
                }else{
                    end--;
                }
            }

            // Skip duplicates
            while(i<n-1 && nums[i+1]==nums[i]){
                i++;
            }
        }   
        
        return ans;
    }
};