// https://leetcode.com/problems/combination-sum-ii/

// Duplicate numbers + Can take only once


// approach1: take or don't take approach at each step
class Solution {
public:

    void backtrack(vector<int> &v, int index, int currentSum, int targetSum, vector<int> current, vector<vector<int> > &ans, bool prevChoosen){
        if(currentSum==targetSum){
            ans.push_back(current);
            return;
        }

        if(index>=v.size() || currentSum>targetSum){
            return;
        }

        // take or don't take

        // don't take
        backtrack(v,index+1,currentSum,targetSum,current,ans, false);

        // take
        // take only if previous duplicate number taken
        // don't start a subset with same number
        // ie. [2,2,3] -> [2,2..] valid [2,...] starting from second 2 would result in duplicates

        // if same as previous number, don't take if previous was not choosen
        if(index>=1 && v[index]==v[index-1] && !prevChoosen) {
            return;
        }

        current.push_back(v[index]);
        backtrack(v,index+1,currentSum+v[index],targetSum,current,ans,true);
        current.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort since duplicates
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        backtrack(candidates, 0, 0, target,{},ans,false);
        return ans;
    }
};c


// approach2: Form subsets at each recursion step, at each step we have all the elements to choose from

class Solution {
public:
    void backtrack(vector<int>& v, int targetSum, int start, int currentSum, vector<int> current, vector<vector<int> > &ans){

        if(currentSum==targetSum){
            ans.push_back(current);
            return;
        }

        if(start>=v.size() || currentSum>targetSum){
            return;
        }

        // at any point can take any number
        // skip number if its a duplicate, take duplicate only if previous duplicate taken
        // ie. can't start a subset again with a same number

        // ex. [2,2,2]
        // 2nd 2 can come if first 2 already take
        // ie. after we take first 2 and call our function again
        // but we can't take it in the same call, ie. start from it otherwise [2(1),2(2 index)] duplicate

        for(int i=start;i<v.size();i++){

            if(i>start && v[i]==v[i-1]){
               continue;// skip same number as start
            }

        

            // take
            current.push_back(v[i]);
            backtrack(v, targetSum,i+1,currentSum+v[i],current,ans);

            // backtrack
            current.pop_back();

        }

        return;


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Duplicate numbers so sort
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        backtrack(candidates, target, 0, 0, {}, ans);
        return ans;
    }
};

