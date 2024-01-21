// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_624880

// matrix multiplication

// A*B m*n and a*b , a==n only then they can be multiplied
// result of A*B is (m*b) matrix

// ABCDE
// Can do
// A(BCDE)
// (AB)(CDE)
// (ABC)(DE)
// (ABCD)(E)

// i,j
// we can divide at
// 01234
// ABCDE
// A|BCDE, AB|CDE , ABC|DE, ABCD|E

// recursion
#include<bits/stdc++.h>
int help(int* arr, int i, int j){
    // Matrix not possible
    if(i>=j){
        return 0;
    }

    if(i+1==j){
        // single matrix
        return 0;
    }
    
    // k can be from i+1 to j-1
    // division from [i..k][k+1,j]
    int mini=INT_MAX-5;
    for(int k=i+1;k<j;k++){
        int left=help(arr,i,k);
        int right=help(arr,k,j);
        int merge=arr[i]*arr[j]*arr[k];
        mini=min(mini, left+right+merge);       
    }

    return mini;

}
int matrixChainMultiplication(int* arr, int n) {
    return help(arr,0,n);
}

// Memo
#include<bits/stdc++.h>
int help(int* arr, int i, int j,vector<vector<int> > &dp){
    // Matrix not possible
    if(i>=j){
        return 0;
    }

    if(i+1==j){
        // single matrix
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    // k can be from i+1 to j-1
    // division from [i..k][k+1,j]
    int mini=INT_MAX-5;
    for(int k=i+1;k<j;k++){
        int left=help(arr,i,k,dp);
        int right=help(arr,k,j,dp);
        int merge=arr[i]*arr[j]*arr[k];
        mini=min(mini, left+right+merge);       
    }

    return dp[i][j]=mini;

}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int> > dp(n+5,vector<int>(n+5,-1));
    return help(arr,0,n,dp);
}