// https://leetcode.com/problems/longest-common-subsequence/

// TLE
class Solution {
public:
    int helper(int i,int j,int n1,int n2,string text1, string text2){
        if(i>=n1 || j>=n2){
            return 0;
        }

        if(text1[i]==text2[j]){
            return 1+helper(i+1,j+1,n1,n2,text1,text2);
        }
        else{
            // match next i
            int op1=helper(i+1,j,n1,n2,text1,text2);
            // or match next j
            int op2=helper(i,j+1,n1,n2,text1,text2);
            return max(op1,op2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        return helper(0,0,n1,n2,text1,text2);
    }
};

// Memo
class Solution {
public:
    int helper(int i,int j,string &text1, string &text2, vector<vector<int> > &dp){
        int n1=text1.length();
        int n2=text2.length();
        if(i==n1 || j==n2){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(text1[i]==text2[j]){
            return dp[i][j]=1+helper(i+1,j+1,text1,text2,dp);
        }
        else{
            return dp[i][j]=max(helper(i+1,j,text1,text2,dp),helper(i,j+1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int> > dp(n1+5,vector<int>(n2+5,-1));
        return helper(0,0,text1,text2,dp);
    }
};

// Table
// if s1[i]==s2[j]
// dp[i][j]=1+dp[i-1][j-1]

// else
// dp[i][j]=max(dp[i-1][j],dp[i][j-1])

// base case
// dp[i][0] = 0 // 0 here means no element of string 2 not the index
// dp[0][j] = 0

// since we consider 0 as no element dp[i][1] will be lcs of text1 and text 2 till 0th index ie 1-1=0
// dp[i][j]= length of lcs for text1[i-1] and text2[j-1]
 
// ans will be dp[n1][n2]
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();

        vector<vector<int> > dp(n1+5,vector<int> (n2+5,0));

        for(int i=0;i<n1;i++){
            dp[i][0]=0;
        }

        for(int j=0;j<n2;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
};