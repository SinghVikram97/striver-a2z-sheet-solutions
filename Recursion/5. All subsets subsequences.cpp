// https://leetcode.com/problems/subsets/


// All elements are given as unique so [1,1] not possible
// here there can be duplicate subsets in above case with our approach

class Solution {
public:
    void generate(vector<int> &nums, int i, vector<int> current, vector<vector<int> > &ans){
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }

        // take or don't take

        // take
        current.push_back(nums[i]);
        generate(nums,i+1,current,ans);

        // backtrack
        current.pop_back();

        generate(nums,i+1,current,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;

        generate(nums,0,{},ans);

        return ans;

    }
};