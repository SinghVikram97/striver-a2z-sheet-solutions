// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

// Recursion - TLE
#include <bits/stdc++.h> 
bool helper(int i,int sum,int n,int target,vector<int> &arr){
    if(sum==target){
        return true;
    }

    if(i>=n){
        return false;
    }

    // take or don't take
    int op1=helper(i+1,sum+arr[i],n,target,arr);

    // don't take
    int op2=helper(i+1,sum,n,target,arr);

    return op1 || op2;
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(0,0,n,k,arr);
}

// Memo
#include <bits/stdc++.h> 
bool helper(int i,int sum,int n,int target,vector<int> &arr,vector<vector<int> > &dp){
    // Extra condition
    if(sum>target){
        return false;
    }
    if(sum==target){
        return true;
    }

    if(i>=n){
        return false;
    }

    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    // take or don't take
    int op1=helper(i+1,sum+arr[i],n,target,arr,dp);

    // don't take
    int op2=helper(i+1,sum,n,target,arr,dp);

    bool ans=op1 || op2;

    dp[i][sum]=ans;

    return ans;
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int> > dp(n,vector<int>(k,-1));
    return helper(0,0,n,k,arr,dp);
}
