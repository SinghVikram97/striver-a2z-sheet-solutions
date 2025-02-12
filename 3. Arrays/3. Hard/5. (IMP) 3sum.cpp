// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
// First do 2 sum
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int start=0;
        int end=n-1;

        // array is sorted
        while(start<end){
            int sum=numbers[start]+numbers[end];

            if(sum==target){
                return {start+1,end+1}; // since one indexed
            }else if(sum<target){
                // move left
                start++;
            }else{
                // move right
                end--;
            }
        }

        return {};
    }
};

// https://leetcode.com/problems/3sum/
// For each element do 2sum so we can do it in n^2
/*
The solution must not have duplicates for example
1, 1, 1, 2, 2 and target = 4

then it should contain [1,1,2] only once in solution

we fix first 1 and then target = 3

1, 1, 1, 2, 2
   l        r

l+r==sum what to do?

Below solution will have duplicates
*/
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
                    start++;
                    end--;
                }else if(sum<newTarget){
                    start++;
                }else{
                    end--;
                }
            }
        }   
        
        return ans;
    }
};

/*
1, 1, 1, 2, 2
   l        r

l+r==sum what to do?

Above solution will have duplicates since we increment both l and r and then again we get 1 and 2
so 2 times we will have [1,1,2] in our ans

We have to skip duplicates twice once inside our 2 sum logic and once outside

*/
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