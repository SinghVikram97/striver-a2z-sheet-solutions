// https://leetcode.com/problems/coin-change/

// Recursion - TLE
class Solution {
public:
    int help(int i,int amount,vector<int> &coins){
        int n=coins.size();

        if(amount<0){
            return -1;
        }

        if(amount==0){
            return 0;
        }

        if(i>=n){
            return -1;
        }

        int op1=help(i,amount-coins[i],coins);
        int op2=help(i+1,amount,coins);

        if(op1==-1 && op2==-1){
            return -1;
        }
        if(op1==-1){
            return op2;
        }
        if(op2==-1){
            return 1+op1;
        }
        return min(1+op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        return help(0,amount,coins);
    }
};

// DP - Memo
class Solution {
public:
    int help(int i,int amount,vector<int> &coins, vector<vector<int> > &dp){
        int n=coins.size();

        if(amount<0){
            return -1;
        }

        if(amount==0){
            return 0;
        }

        if(i>=n){
            return -1;
        }

        if(dp[i][amount]!=-2){
            return dp[i][amount];
        }

        int op1=help(i,amount-coins[i],coins,dp);
        int op2=help(i+1,amount,coins,dp);

        if(op1==-1 && op2==-1){
            return dp[i][amount]=-1;
        }
        if(op1==-1){
            return dp[i][amount]=op2;
        }
        if(op2==-1){
            return dp[i][amount]=1+op1;
        }
        return dp[i][amount]=min(1+op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int> > dp(n+5,vector<int>(amount+5,-2));
        return help(0,amount,coins,dp);
    }
};