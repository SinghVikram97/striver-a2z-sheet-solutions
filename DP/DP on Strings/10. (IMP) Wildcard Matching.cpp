// https://leetcode.com/problems/wildcard-matching/

// Memory limit exceeded
class Solution {
public:
    bool help(int i, int j, string s, string p){
        int m=s.length();
        int n=p.length();

        if(i==m && j==n){
            return true;
        }

        if(i==m){
            for(int k=j;k<n;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(j==n){
            return false;
        }

        if(p[j]=='*'){
            // match empty sequence
            int op1=help(i,j+1,s,p);
            // use it once to match a single char
            int op2=help(i+1,j+1,s,p);
            // keep using it for next char
            int op3=help(i+1,j,s,p);
            return op1 || op2 || op3;
        }

        else if(p[j]=='?'){
            // match with single character
            return help(i+1,j+1,s,p);
        }
        else{
            if(s[i]==p[j]){
                return help(i+1,j+1,s,p);
            }
            else{
                return false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        return help(0,0,s,p);
    }
};

// Memo
class Solution {
public:
    bool help(int i, int j, string s, string p, vector<vector<int> > &dp){
        int m=s.length();
        int n=p.length();

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==m && j==n){
            return dp[i][j]=true;
        }

        if(i==m){
            for(int k=j;k<n;k++){
                if(p[k]!='*'){
                    return dp[i][j]=false;
                }
            }
            return dp[i][j]=true;
        }

        if(j==n){
            return dp[i][j]=false;
        }

        if(p[j]=='*'){
            // match empty sequence
            int op1=help(i,j+1,s,p,dp);
            // use it once to match a single char
            int op2=help(i+1,j+1,s,p,dp);
            // keep using it for next char
            int op3=help(i+1,j,s,p,dp);
            return dp[i][j]=op1 || op2 || op3;
        }

        else if(p[j]=='?'){
            // match with single character
            return dp[i][j]=help(i+1,j+1,s,p,dp);
        }
        else{
            if(s[i]==p[j]){
                return dp[i][j]=help(i+1,j+1,s,p,dp);
            }
            else{
                return dp[i][j]=false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int> > dp(m+5,vector<int>(n+5,-1));
        return help(0,0,s,p,dp);
    }
};

// TLE
class Solution {
public:
    bool help(int i, int j, string s, string p, vector<vector<int> > &dp){
        int m=s.length();
        int n=p.length();

        cout<<i<<" "<<j<<endl; 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==m && j==n){
            return dp[i][j]=true;
        }

        if(i==m){
            for(int k=j;k<n;k++){
                if(p[k]!='*'){
                    return dp[i][j]=false;
                }
            }
            return dp[i][j]=true;
        }

        if(j==n){
            return dp[i][j]=false;
        }

        if(p[j]=='*'){
            for(int k=i;k<=m;k++){
               bool ans=help(k,j+1,s,p,dp);
               if(ans){
                   return dp[i][j]=true;
               }
               else{
                   continue;
               }
            }
            return dp[i][j]=false;
        }

        else if(p[j]=='?'){
            // match with single character
            return dp[i][j]=help(i+1,j+1,s,p,dp);
        }
        else{
            if(s[i]==p[j]){
                return dp[i][j]=help(i+1,j+1,s,p,dp);
            }
            else{
                return dp[i][j]=false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int> > dp(m+5,vector<int>(n+5,-1));
        return help(0,0,s,p,dp);
    }
};

// MLE
class Solution {
public:
    bool help(int i, int j, string s, string p){
        if(i<0 && j<0){
            return true;
        }

        if(i<0){
            // s is empty
            // p has to be all star as star can match with empty string
            for(int k=j;k>=0;k--){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(j<0){
            return false;
        }

        if(p[j]=='*'){
            // match with empty sequence and finish
            // or match with character and keep star
            return help(i,j-1,s,p) || help(i-1,j,s,p);
        }else if(s[i]==p[j] || p[j]=='?'){
            return help(i-1,j-1,s,p);
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        return help(m-1,n-1,s,p);
    }
};

// DP
// dp[i][j]

// if p[j]=='*'
// dp[i][j]=dp[i][j-1] || dp[i-1][j]

// if s[i]==p[j] || p[j]=='?'
// dp[i][j]=dp[i-1][j-1]

// else
// dp[i][j]=false

// dp[i][0]  = 0 , pattern empty 
// dp[0][j]  = 0 / 1 depends
// dp[0][0]  = 1
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();

        vector<vector<int> > dp(m+5,vector<int>(n+5,-1));

        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }

        bool foundOtherChar=false;
        for(int j=0;j<=n;j++){
            if(j==0){
                dp[0][j]=1;
                continue;
            }
            
            if(p[j-1]=='*' && !foundOtherChar){
                dp[0][j]=1;
                continue;
            }

            else {
                foundOtherChar=true;
                dp[0][j]=0;
                continue;
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }

        return dp[m][n];
    }
}; 

// We don't need op3 in memo -> this passes
class Solution {
public:
    bool help(int i, int j, string &s, string &p, vector<vector<int> > &dp){
        int m=s.length();
        int n=p.length();

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==m && j==n){
            return dp[i][j]=true;
        }

        if(i==m){
            for(int k=j;k<n;k++){
                if(p[k]!='*'){
                    return dp[i][j]=false;
                }
            }
            return dp[i][j]=true;
        }

        if(j==n){
            return dp[i][j]=false;
        }

        if(p[j]=='*'){
            // match empty sequence
            int op1=help(i,j+1,s,p,dp);
            // use it once to match a single char
            // int op2=help(i+1,j+1,s,p,dp);
            // keep using it for next char
            int op3=help(i+1,j,s,p,dp);
            return dp[i][j]=op1 || op3;
        }

        else if(p[j]=='?'){
            // match with single character
            return dp[i][j]=help(i+1,j+1,s,p,dp);
        }
        else{
            if(s[i]==p[j]){
                return dp[i][j]=help(i+1,j+1,s,p,dp);
            }
            else{
                return dp[i][j]=false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int> > dp(m+5,vector<int>(n+5,-1));
        return help(0,0,s,p,dp);
    }
};