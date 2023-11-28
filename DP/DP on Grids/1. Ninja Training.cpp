// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003

// dp[i][j] = max points on day i doing activity j
// dp[i][j]= max(dp[i-1][k]) where k=0 to n-1 and k!=j

// dp[0][j] = points[0][j]

// j is 3

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> > dp(n,vector<int>(3,-1));

    for(int j=0;j<3;j++){
        dp[0][j]=points[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k!=j){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+points[i][j]);
                }
            }
        }
    }

    int maxi=-1;
    for(int j=0;j<3;j++){
        maxi=max(dp[n-1][j],maxi);
    }

    return maxi;

}