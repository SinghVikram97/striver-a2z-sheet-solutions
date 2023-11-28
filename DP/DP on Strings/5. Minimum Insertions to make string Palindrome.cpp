// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// if characters not equal
// 2 options either insert at start
// or either insert at end

// mbadm 
// 01234

// 0==4 -> 1-3
// b!=d either insert b at 3 or insert d at 1

// Recursive - TLE
class Solution {
public:
    int help(int s, int e, string str){
        if(s>e){
            return 0; 
        }

        if(s==e){
            return 0;
        }

        if(str[s]==str[e]){
            return help(s+1,e-1,str);
        }else{
            int op1=help(s+1,e,str);
            int op2=help(s,e-1,str);
            return 1+min(op1,op2);
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        if(n==0 || n==1){
            return 0;
        }
        return help(0,n-1,s);
    }
};

// Memo 
class Solution {
public:
    int help(int s, int e, string str, vector<vector<int> > &dp){
        if(s>e){
            return 0; 
        }

        if(s==e){
            return 0;
        }

        if(dp[s][e]!=-1){
            return dp[s][e];
        }

        if(str[s]==str[e]){
            return dp[s][e]=help(s+1,e-1,str,dp);
        }else{
            int op1=help(s+1,e,str,dp);
            int op2=help(s,e-1,str,dp);
            return dp[s][e]=1+min(op1,op2);
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        if(n==0 || n==1){
            return 0;
        }
        vector<vector<int> > dp(n+5,vector<int>(n+5,-1));
        return help(0,n-1,s,dp);
    }
};