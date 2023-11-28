//  https://leetcode.com/problems/subsets/
// same as previous but using different approach which will be useful in next question

// 2 approaches for calculating subset
// In previous we had either select an element or don't select an element
// and at last we would have the final subset

// In this approach we start with an empty data structure.
// In the first recursion, call make a subset of size one, 
// in the next recursion call a subset of size 2, and so on. 
// But first, in order to make a subset of size one what options do we have?
// We have the full array 




class Solution {
public:
    void generate(vector<int> &nums, int start, vector<int> current, vector<vector<int> > &ans){
        ans.push_back(current);

        // take or don't take
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            generate(nums,i+1,current,ans);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;

        generate(nums,0,{},ans);

        return ans;

    }
};