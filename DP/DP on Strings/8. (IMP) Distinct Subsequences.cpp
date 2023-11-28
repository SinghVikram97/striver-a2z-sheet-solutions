// https://leetcode.com/problems/distinct-subsequences/

// Recursion - Memory limit exceeded
class Solution {
public:
    void help(string temp, int i, string s, string t, int &ans){
        int n=s.length();
        if(i==n){
            if(temp==t){
                ans++;
                return;
            }
            return;
        }

        // can take or not
        help(temp+s[i],i+1, s, t, ans);
        help(temp,i+1,s,t,ans);
    }
    int numDistinct(string s, string t) {
        int ans=0;
        help("",0,s,t,ans);
        return ans;
    }
};

// Similar to coind change number of ways to make t from s 
// TLE
class Solution {
public:
    int help(int i, int j, string s, string t){

        int m=s.length();
        int n=t.length();

        if(j==n){
            return 1;
        }

        if(i==m){
            return 0;
        }

        if(s[i]==t[j]){
            // take or maybe same character down the line which will match 
            // so 2 options

            // taking so next we need to match next character in t
            int op1=help(i+1,j+1,s,t);

            // don't match yet so skip this character
            int op2=help(i+1,j,s,t);

            return op1+op2;
        }
        else{
            // can't take
            // move forward
            return help(i+1,j,s,t);
        }


    }
    int numDistinct(string s, string t) {
        return help(0,0,s,t);
    }
};

// Memo
class Solution {
public:
    int help(int i, int j, string s, string t, vector<vector<int> > &dp){

        int m=s.length();
        int n=t.length();

        if(j==n){
            return 1;
        }

        if(i==m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            // take or maybe same character down the line which will match 
            // so 2 options

            // taking so next we need to match next character in t
            int op1=help(i+1,j+1,s,t,dp);

            // don't match yet so skip this character
            int op2=help(i+1,j,s,t,dp);

            return dp[i][j]=op1+op2;
        }
        else{
            // can't take
            // move forward
            return dp[i][j]=help(i+1,j,s,t,dp);
        }


    }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int> > dp(m+5,vector<int>(n+5,-1));
        return help(0,0,s,t,dp);
    }
};