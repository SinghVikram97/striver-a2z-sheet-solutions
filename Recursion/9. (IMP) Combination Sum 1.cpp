// https://leetcode.com/problems/combination-sum/


// Distinct numbers + Can take more than once

// approach1: take or don't take approach at each step

class Solution {
public:

    void calculateSum(vector<int> nums, int targetSum, int currentSum, int index, vector<int> currentArray,vector<vector<int> > &ans){
        int n = nums.size();

        if(currentSum==targetSum){
            ans.push_back(currentArray);
            return;
        }

        if(index==n || currentSum>targetSum){
            return;
        }

        // take, note can take an element again
        currentArray.push_back(nums[index]);
        calculateSum(nums, targetSum, currentSum+nums[index],index,currentArray,ans);

        // backtrack
        currentArray.pop_back();

        // don't take
        calculateSum(nums,targetSum,currentSum,index+1,currentArray,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        calculateSum(candidates,target,0,0,{},ans);
        return ans;
    }
};


// approach2: Form subsets at each recursion step, at each step we have all the elements to choose from

class Solution {
public:

    void calculateSum(vector<int> v, int index, int targetSum, int currentSum, vector<int> current, vector<vector<int> > &ans){

        if(currentSum==targetSum){
            ans.push_back(current);
        }

        if(currentSum>targetSum){
            return;
        }

        // we can choose from any of the number in array at every point ( can take number multiple times )
        for(int i=index;i<v.size();i++){
            // take
            current.push_back(v[i]);
            calculateSum(v,i,targetSum,currentSum+v[i],current,ans); // pass i as index as can take this number again
            // but we need to pass i as we start i from index ex. [2,3,6,7] if we take 3 we don't want to take 2 again 
            // it will result in duplicate set [2,3] and [3,2]
            //backtrack
            current.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        calculateSum(candidates,0,target,0,{},ans);
        return ans;
    }
};