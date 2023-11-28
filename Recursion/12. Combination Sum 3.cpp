// https://leetcode.com/problems/combination-sum-iii/


// [1,2......9]

// Subset of size k with sum n 


// Approach 1 - take or don't take
// In this we are not sure when to stop 
// In this we find sum of all subsets
// if it satisfies both sum and size then add to ans

class Solution {
public:

    void backtrack(vector<int> &v, int i, int targetSize, int targetSum, int currentSum, vector<int> currentArray, vector<vector<int> > &ans) {
        if(i==v.size()){
            if(currentSum==targetSum && currentArray.size()==targetSize){
                ans.push_back(currentArray);
            }
            return;
        }

        // take
        currentArray.push_back(v[i]);
        backtrack(v,i+1,targetSize,targetSum,currentSum+v[i],currentArray,ans);

        // backtrack
        currentArray.pop_back();

        // don't take
        backtrack(v,i+1,targetSize,targetSum,currentSum,currentArray,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
        }
        vector<vector<int> > ans;
        backtrack(v,0,k,n,0,{},ans);
        return ans;
    }
};


// Approach 2- Optimized
// Stop at subsets if size is exhausted
// ie. when u take an element reduce the size
class Solution {
public:

    void backtrack(vector<int> v, int i, int targetSize, int targetSum, int currentSum, vector<int> currentArray, vector<vector<int> > &ans){
        if(targetSize==0){
            if(currentSum==targetSum){
                ans.push_back(currentArray);
            }
            return;
        }

        if(i==v.size()) {
            return; // subset with less elements we didn't choose enough elements and reached the end
        }

        // take
        currentArray.push_back(v[i]);
        backtrack(v,i+1,targetSize-1,targetSum,currentSum+v[i],currentArray,ans);

        // backtrack
        currentArray.pop_back();

        // don't take
        backtrack(v,i+1,targetSize,targetSum,currentSum,currentArray,ans);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
        }
        vector<vector<int> > ans;
        backtrack(v,0,k,n,0,{},ans);
        return ans;
    }
};

// Approach 3 - Form subset of size n at depth n of recursion tree
// at each step we can choose from the whole array ( approach 2 of subset )
// whole array ie. numbers from 1 to 9

class Solution {
public:

    void backtrack(int targetSize, int targetSum, int start, int currentSum, vector<int> currentArray, vector<vector<int> > &ans) {

        if(targetSize==0){
            if(currentSum==targetSum) {
                ans.push_back(currentArray);
            }
            return;
        }

        // we can choose from start to 9
        for(int i=start;i<=9;i++){

            // take
            currentArray.push_back(i);
            backtrack(targetSize-1,targetSum,i+1,currentSum+i,currentArray,ans);

            // backtrack
            currentArray.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        backtrack(k,n,1,0,{},ans);
        return ans;
    }
};