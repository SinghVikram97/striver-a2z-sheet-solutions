// https://leetcode.com/problems/delete-operation-for-two-strings/

// Recursion - TLE
class Solution {
public:
    int help(int i, int j, int n, int m, string &word1, string &word2){

        if(i>=n && j>=m){
            return 0;
        }

        if(i>=n){
            return m-j; // these many characters left for 2nd string
        }

        if(j>=m){
            return n-i; // these many characters left for 1st string
        }

        if(word1[i]==word2[j]){
            return help(i+1,j+1,n,m,word1,word2);
        }
        else{
            // can delete word1[i] or word2[j]
            int op1=help(i+1,j,n,m,word1,word2);
            int op2=help(i,j+1,n,m,word1,word2);
            return 1+min(op1,op2);
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        return help(0,0,n,m,word1,word2);
    }
};

// Memo
class Solution {
public:
    int help(int i, int j, int n, int m, string &word1, string &word2, vector<vector<int> > &dp){

        if(i>=n && j>=m){
            return 0;
        }

        if(i>=n){
            return m-j; // these many characters left for 2nd string
        }

        if(j>=m){
            return n-i; // these many characters left for 1st string
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]=help(i+1,j+1,n,m,word1,word2,dp);
        }
        else{
            // can delete word1[i] or word2[j]
            int op1=help(i+1,j,n,m,word1,word2,dp);
            int op2=help(i,j+1,n,m,word1,word2,dp);
            return dp[i][j]=1+min(op1,op2);
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int> > dp(n+5,vector<int> (m,-1));
        return help(0,0,n,m,word1,word2,dp);
    }
};