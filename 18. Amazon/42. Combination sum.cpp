// https://leetcode.com/problems/combination-sum/description/
class Solution {
public:
    void help(vector<int> &nums, int index, int sum, int targetSum, vector<int> temp, vector<vector<int> > &ans){
        int n=nums.size();

        if(index==n && sum==targetSum){
            ans.push_back(temp);
            return;
        }

        if(index==n){
            return;
        }

        if(sum>targetSum){
            return;
        }

        // take
        temp.push_back(nums[index]);
        // since we can take unlimited times don't increment index
        help(nums, index, sum+nums[index], targetSum, temp, ans);

        // don't take
        temp.pop_back();
        help(nums, index+1, sum, targetSum, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int> > ans;
        help(candidates, 0, 0, target, temp, ans);
        return ans;
    }
};