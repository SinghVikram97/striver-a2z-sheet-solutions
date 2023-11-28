// https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

int lcs(string &str1, string &str2){
    int m=str1.length();
    int n=str2.length();

    vector<vector<int> > dp(m+5,vector<int>(n+5,-1));

    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }

    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

    // dp[i][0] is 2nd string empty
    // dp[i][1] is 2nd string one character ie. till str[0]

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1]; // continue the substring
            }
            else{
                dp[i][j]=0; // can't have discontinous string
            }
        }
    }

    // return the max value in the matrix
    // as substring can end anywhere
    int maxi=-1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
}