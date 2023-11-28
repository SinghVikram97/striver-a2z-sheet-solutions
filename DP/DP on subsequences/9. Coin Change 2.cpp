// https://leetcode.com/problems/coin-change-ii/description/

// can take a coin as many times as we want

// TLE
class Solution {
public:
    int help(int i,int sum,int n,vector<int> &coins,int amount){
        if(sum==amount){
            return 1;
        }
        if(sum>amount){
            return 0;
        }
        if(i>=n){
            return 0;
        }

        // take coin
        int op1=help(i,sum+coins[i],n,coins,amount);
        // don't take coin
        int op2=help(i+1,sum,n,coins,amount);

        return op1+op2;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return help(0,0,n,coins,amount);
    }
};

// Memo
class Solution {
public:
    int help(int i,int sum,int n,vector<int> &coins,int amount, vector<vector<int> > &dp){
        if(sum==amount){
            return 1;
        }
        if(sum>amount){
            return 0;
        }
        if(i>=n){
            return 0;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        // take coin
        int op1=help(i,sum+coins[i],n,coins,amount,dp);
        // don't take coin
        int op2=help(i+1,sum,n,coins,amount,dp);

        return dp[i][sum]=op1+op2;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> > dp(n+1,vector<int>(amount+1,-1));
        return help(0,0,n,coins,amount,dp);
    }
};