// https://leetcode.com/problems/subsets-ii/

// can't remove duplicates and find the ans

// ex. [1,2,1,3]-> [1,1,3] valid
// sort [1,1,2,3]
// 

// so don't include it at start but can include it at the middle
// ie. 2nd one can come with 1st one
// but 2nd one can't have a subset starting with it since that would be duplicate

// don't include at start mean for ex. [2,3,3,4]
// start is at i=1
// now include first 3 but skip second 3 when we are calculating [2...][3,3,4]
// when calculating [2,3...] [3,4] we will have [2,3,3] so thats done


// https://leetcode.com/problems/subsets-ii/solutions/169226/java-two-way-of-recursive-thinking/

class Solution {
public:
    void generate(vector<int> &nums, int start, vector<int> current, vector<vector<int> > &ans){
        ans.push_back(current);

        // take or don't take
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            generate(nums,i+1,current,ans);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        generate(nums,0,{},ans);

        return ans;

    }
};



// 2nd approach which uses approach in 5th problem-> take or don't take
// [2,3,3,4]
// Now take the second 3rd only with the first one, to make subsets like [2,3,3]
// If we take it as a start then we would have duplicates like [3,4]

// so if number same as previous, choose only if previous WAS CHOOSEN

class Solution {
public:

    void generate(vector<int> &nums, int i, vector<int> current, vector<vector<int> > &ans, bool choosePre){
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }

        // take or don't take

        // don't take
        generate(nums,i+1,current,ans,false);

        // if same as previous number, don't take if previous was not choosen
        if(i>=1 && nums[i]==nums[i-1] && !choosePre){
            return;
        } 

        
        current.push_back(nums[i]);
        generate(nums,i+1,current,ans,true);

        // backtrack
        current.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int> > ans;

        generate(nums,0,{},ans,false);

        return ans;
    }
};