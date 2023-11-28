// https://www.codingninjas.com/studio/problems/frog-jump_3621012
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int size=heights.size();
    vector<int> dp(size);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);

    for(int i=2;i<size;i++){
       dp[i]=min(abs(heights[i]-heights[i-1])+dp[i-1],abs(heights[i]-heights[i-2])+dp[i-2]);
    }

    return dp[size-1];
}