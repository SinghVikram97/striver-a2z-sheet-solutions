// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542


// can take an item or not take it
// return max value

// TLE
#include<bits/stdc++.h>
using namespace std; 

// returns maximum value
int help(int i,vector<int> weight,vector<int> value,int n,int maxWeight){
    if(i>=n){
        return 0;
    }

    // take
    int op1=0;
    if(maxWeight-weight[i]>=0){
        // can take
        op1=value[i]+help(i+1,weight,value,n,maxWeight-weight[i]);
    }

    // don't take
    int op2=help(i+1,weight,value,n,maxWeight);

    return max(op1,op2);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return help(0,weight,value,n,maxWeight);
}

// Memo
#include<bits/stdc++.h>
using namespace std; 

// returns maximum value
int help(int i,vector<int> weight,vector<int> value,int n,int maxWeight,  vector<vector<int> > &dp){
    if(i>=n){
        return 0;
    }

    if(dp[i][maxWeight]!=-1){
        return dp[i][maxWeight];
    }

    // take
    int op1=0;
    if(maxWeight-weight[i]>=0){
        // can take
        op1=value[i]+help(i+1,weight,value,n,maxWeight-weight[i],dp);
    }

    // don't take
    int op2=help(i+1,weight,value,n,maxWeight,dp);

    dp[i][maxWeight]=max(op1,op2);
	return dp[i][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int> > dp(n+5,vector<int> (maxWeight+5,-1));
	return help(0,weight,value,n,maxWeight,dp);
}