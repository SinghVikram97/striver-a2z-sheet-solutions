// https://leetcode.com/problems/burst-balloons/

/*
Intuition ->
we have [i-1, i, i+1....k...., j-1, j, j+1]
now assume we burst i..k-1 and k+1....j
and now are left with i-1, k, j+1

so we have [i,j]
we select k which can be from i...j 
k is the last ballon left
*/

// Recursion - TLE
class Solution {
public:
    int cost(int i, int j, vector<int> &v){
        if(i>j){
            return 0;
        }

        if(i==j){
            return v[i-1]*v[i]*v[i+1];
        }

        int ans=-1;

        for(int k=i;k<=j;k++){
            // assume k last ballon left
            // ie. burst from i..k-1
            // from k+1...j
            // and then for k we have i-1 and j+1
            int op=v[i-1]*v[j+1]*v[k]+cost(i,k-1,v)+cost(k+1,j,v);
            cout<<op<<endl;
            ans=max(ans, op);
        }

        return ans;
    }
    int maxCoins(vector<int>& nums) {
        // add 1 to front and back for handling boundaries
        vector<int> v;
        v.push_back(1);
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        v.push_back(1);
        return cost(1, nums.size(), v);
    }
};

// Memo
class Solution {
public:
    int cost(int i, int j, vector<int> &v, vector<vector<int> > &dp){
        if(i>j){
            return 0;
        }

        if(i==j){
            return v[i-1]*v[i]*v[i+1];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=-1;

        for(int k=i;k<=j;k++){
            int op=v[i-1]*v[j+1]*v[k]+cost(i,k-1,v,dp)+cost(k+1,j,v,dp);
            ans=max(ans, op);
        }

        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int> > dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        vector<int> v;
        v.push_back(1);
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        v.push_back(1);
        return cost(1, nums.size(), v,dp);
    }
};