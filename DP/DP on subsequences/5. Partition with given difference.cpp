// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628

// 2 subsets with given diff
// can be 1st subset or 2nd
// sum1-sub2 == diff ( given that sum1 should be greater than sum2 )

// we know sum1 we can calculate sum2
// sum2=totalSum-sum1

// Recursion - TLE
#include <bits/stdc++.h> 
int helper(int i,int sum1,int n,int targetSum,vector<int> &arr,int totalSum){
    if(i==n){
        int sum2=totalSum-sum1;
        if(sum1-sum2==targetSum){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    // 2 options go in 1st subset or 2nd
    int op1=helper(i+1,sum1+arr[i],n,targetSum,arr,totalSum);
    int op2=helper(i+1,sum1,n,targetSum,arr,totalSum);
    return op1+op2;
}
int countPartitions(int n, int d, vector<int> &arr) {
     int totalSum=0;
     for(int i=0;i<n;i++){
        totalSum+=arr[i];
     }

     return helper(0,0,n,d,arr,totalSum);
}

// DP - Memo
#include <bits/stdc++.h> 
#define m 1000000007
long long int helper(int i,int sum1,int n,int targetSum,vector<int> &arr,int totalSum, vector<vector<long long int> > &dp){
    if(i==n){
        int sum2=totalSum-sum1;
        if(sum1-sum2==targetSum){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[i][sum1]!=-1){
        return dp[i][sum1];
    }
    
    // 2 options go in 1st subset or 2nd
    long long int op1=helper(i+1,sum1+arr[i],n,targetSum,arr,totalSum,dp);
    long long int op2=helper(i+1,sum1,n,targetSum,arr,totalSum,dp);
    long long int ans=((op1%m)+(op2%m))%m;
    dp[i][sum1]=ans;
    return ans;
}
int countPartitions(int n, int d, vector<int> &arr) {
     int totalSum=0;
     for(int i=0;i<n;i++){
        totalSum+=arr[i];
     }

     vector<vector<long long int> > dp(n+5,vector<long long int>(totalSum+5,-1));

     return helper(0,0,n,d,arr,totalSum,dp);
}

