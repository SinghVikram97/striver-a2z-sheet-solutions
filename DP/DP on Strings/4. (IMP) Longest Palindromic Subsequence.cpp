// https://leetcode.com/problems/longest-palindromic-subsequence/

// LCS of string and its reverse
        // abdefbazyk
        // zykabfedba
        // ans: abba
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
    int longestPalindromeSubseq(string s) {
        string str2=s;
        reverse(str2.begin(),str2.end());
        return longestCommonSubsequence(s,str2);
    }
};

// Without reversing the string?
// start from beginging and end
// abdefbazyk
// if str[i]!=str[j]
// 2 options move front or move backward
// else if equal then 1+ move both sides

// Recursion - TLE
class Solution {
public:
    int help(int s, int e, string &str){
        if(s>e){
            return 0;
        }

        if(s==e){
            return 1;
        }

        if(str[s]==str[e]){
            return 2+help(s+1,e-1,str);
        }
        else{
            int op1=help(s+1,e,str);
            int op2=help(s,e-1,str);
            return max(op1,op2);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        if(n==0 || n==1){
            return n;
        }
        return help(0,n-1,s);
    }
};

// Memo
class Solution {
public:
    int help(int s, int e, string &str, vector<vector<int> > &dp){
        if(s>e){
            return 0;
        }

        if(s==e){
            return 1;
        }

        if(dp[s][e]!=-1){
            return dp[s][e];
        }

        if(str[s]==str[e]){
            return dp[s][e]=2+help(s+1,e-1,str,dp);
        }
        else{
            int op1=help(s+1,e,str,dp);
            int op2=help(s,e-1,str,dp);
            return dp[s][e]=max(op1,op2);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        if(n==0 || n==1){
            return n;
        }
        vector<vector<int> > dp(n+5,vector<int> (n+5,-1));
        return help(0,n-1,s, dp);
    }
};