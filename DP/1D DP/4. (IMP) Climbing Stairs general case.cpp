// https://www.codingninjas.com/studio/problems/minimal-cost_8180930
int minimizeCost(int n, int k, vector<int> &height){

    if(n==1){
        return 0;
    }

    vector<int> dp(n,INT_MAX-5);

    dp[0]=0;    
    dp[1]=abs(height[1]-height[0]);

    for(int i=2;i<n;i++){
        // 1 to k steps
        for(int step=1;step<=k;step++){
            if(i-step>=0){
                dp[i]=min(dp[i],dp[i-step]+abs(height[i]-height[i-step]));
            }
        }
    }

    return dp[n-1];
}