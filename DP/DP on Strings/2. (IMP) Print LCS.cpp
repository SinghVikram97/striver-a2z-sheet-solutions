// https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383
string findLCS(int n, int m,string &s1, string &s2){
	    vector<vector<int> > dp(n+5,vector<int> (m+5,0));

        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }

        for(int j=0;j<m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // start from bottom
        int i=n;
        int j=m;

        string ans="";

        while(i>=1 && j>=1){
            if(s1[i-1]==s2[j-1]){
                // move diagonally up
                ans+=s1[i-1];
                i=i-1;
                j=j-1;
            }
            else{
                // move to max
                if(dp[i-1][j]>dp[i][j-1]){
                    // move up
                    i=i-1;
                }else{
                    // move down
                    j=j-1;
                }
            }
        }
		reverse(ans.begin(),ans.end());
        return ans;

}