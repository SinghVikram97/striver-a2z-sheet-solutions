// https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885

// earlier we kept track of i and j
// here we have 2 people so we need to keep track of alice and bob
// we can keep track by keeping track of (ai,aj) for alice and (bi,bj) for bob
// but since they both move down at same time so they will move down together
// so we can keep common row no ie. i
// so (i,aj,bj)

// 3 options
// i+1,j or i+1,j-1 or i+1,j+1

// if both alice and bob land on same position
// we take chocolate once

// f(i,aj,bj) = f(i+1,aj)


// Recursion - TLE
#include <bits/stdc++.h> 
vector<int> v={-1,0,1};
int helper(int i,int aj,int bj,int m,int n,vector<vector<int> > &grid){

    if(i<0 || i>=m){
        return INT_MIN+5;
    }

    if(aj<0 || aj>=n || bj<0 || bj>=n){
        return INT_MIN+5;
    }

    // last row
    if(i==m-1){
        // if they both land on same cell just take once
        if(aj==bj){
            return grid[i][aj];
        }
        else{
            // take both
            return grid[i][aj]+grid[i][bj];
        }
    }

    // alice has 3 options
    // bob has 3 options
    // total 9 permutations

    int maxi=INT_MIN;
    for(int a=0;a<v.size();a++){
        for(int b=0;b<v.size();b++){
            maxi=max(maxi,helper(i+1,aj+v[a],bj+v[b],m,n,grid));
        }
    }

    if(aj==bj){
        // pick once
        return grid[i][aj]+maxi;
    }
    else{
        return grid[i][aj]+grid[i][bj]+maxi;
    }

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   int m=r;
   int n=c;
   return helper(0,0,n-1,m,n,grid);
}


// MEMO - 3D DP, i,aj,bj
#include <bits/stdc++.h> 
vector<int> v={-1,0,1};
int helper(int i,int aj,int bj,int m,int n,vector<vector<int> > &grid, vector<vector<vector<int> > > &dp){

    if(i<0 || i>=m){
        return INT_MIN+5;
    }

    if(aj<0 || aj>=n || bj<0 || bj>=n){
        return INT_MIN+5;
    }

    // last row
    if(i==m-1){
        // if they both land on same cell just take once
        if(aj==bj){
            return grid[i][aj];
        }
        else{
            // take both
            return grid[i][aj]+grid[i][bj];
        }
    }

    if(dp[i][aj][bj]!=-1){
        return dp[i][aj][bj];
    }

    // alice has 3 options
    // bob has 3 options
    // total 9 permutations

    int maxi=INT_MIN;
    for(int a=0;a<v.size();a++){
        for(int b=0;b<v.size();b++){
            maxi=max(maxi,helper(i+1,aj+v[a],bj+v[b],m,n,grid,dp));
        }
    }

    if(aj==bj){
        // pick once
        return dp[i][aj][bj]=grid[i][aj]+maxi;
    }
    else{
        return dp[i][aj][bj]=grid[i][aj]+grid[i][bj]+maxi;
    }

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   int m=r;
   int n=c;
   vector<vector<vector<int> > > dp(m,vector<vector<int> > (n,vector<int> (n,-1)));
   return helper(0,0,n-1,m,n,grid,dp);
}
