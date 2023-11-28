// https://leetcode.com/problems/shortest-common-supersequence/

// recursive - memory limit exceeded
class Solution {
public:
    string help(int i, int j, int n, int m, string &word1, string &word2){

        if(i>=n && j>=m){
            return "";
        }

        if(i>=n){
            string temp="";
            for(int k=j;k<m;k++){
                temp+=word2[k];
            }
            return temp;
        }

        if(j>=m){
            string temp="";
            for(int k=i;k<n;k++){
                temp+=word1[k];
            }
            return temp;
        }

        if(word1[i]==word2[j]){
            return word1[i]+help(i+1,j+1,n,m,word1,word2);
        }
        else{
            // can take word1[i] or word2[j]
            // since word2[j] can match with some subsequence in word1 later
            string op1=word1[i]+help(i+1,j,n,m,word1,word2);
            string op2=word2[j]+help(i,j+1,n,m,word1,word2);
            if(op1.length()<op2.length()){
                return op1;
            }
            else{
                return op2;
            }
        }

    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        return help(0,0,n,m,str1,str2);
    }
};

// Memo - Memory Limit Exceeded
class Solution {
public:
    string help(int i, int j, int n, int m, string &word1, string &word2, vector<vector<string> > &dp){

        if(i>=n && j>=m){
            return "";
        }

        if(i>=n){
            string temp="";
            for(int k=j;k<m;k++){
                temp+=word2[k];
            }
            return temp;
        }

        if(j>=m){
            string temp="";
            for(int k=i;k<n;k++){
                temp+=word1[k];
            }
            return temp;
        }

        if(dp[i][j]!="-1"){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]=word1[i]+help(i+1,j+1,n,m,word1,word2,dp);
        }
        else{
            // can take word1[i] or word2[j]
            // since word2[j] can match with some subsequence in word1 later
            string op1=word1[i]+help(i+1,j,n,m,word1,word2,dp);
            string op2=word2[j]+help(i,j+1,n,m,word1,word2,dp);
            if(op1.length()<op2.length()){
                return dp[i][j]=op1;
            }
            else{
                return dp[i][j]=op2;
            }
        }

    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<string> > dp(n+5,vector<string> (m+5,"-1"));
        return help(0,0,n,m,str1,str2,dp);
    }
};

// Take LCS of string 1 and string 2
// take characters - lcs from s1 + lcs + characters - lcs from s2

// Length of shortest commmon supersequence = s1.length()+s2.length()-length(lcs)


// use LCS table
// if s1[i]==s2[j] take s1[i] and move diagonally upwards
// else move towards max, and add whatever you are discarding in the answer
// suppose you move to dp[i-1][j] from dp[i][j] then add str1[j-1] in the answer
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();

        vector<vector<int> > dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            dp[i][0]=0;
        }

        for(int j=0;j<n;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int lcsLength=dp[m][n];

        // Optimize otherwise TLE
        // Both strings same
        if(lcsLength==m && lcsLength==n){
            return str1;
        }

        // Traverse the table
        int i=m;
        int j=n;
        string ans="";
        while(i>=1 && j>=1){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans+=str1[i-1]; // since string one index behind
                    i--;
                }
                else{
                    ans+=str2[j-1];
                    j--;
                }
            }
        }

        // in first string there are still some characters remaining
        // while second string is finished
        while(i>=1){
            ans+=str1[i-1];
            i--;
        }
        while(j>=1){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};