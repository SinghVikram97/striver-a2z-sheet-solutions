// https://leetcode.com/problems/valid-parenthesis-string/description/

// TLE
class Solution {
public:
    bool help(string s, int index, int openCount){
        int n=s.size();
        if(n==index){
            if(openCount==0){
                return true;
            }
            else{
                return false;
            }
        }

        if(s[index]=='('){
            return help(s,index+1,openCount+1);
        }
        else if(s[index]==')'){
            if(openCount==0){
                return false;
            }
            else{
                return help(s,index+1,openCount-1);
            }
        }else if(s[index]=='*'){
            bool ans;
            bool op1=help(s,index+1,openCount);
            bool op2=help(s,index+1,openCount+1);

            ans=op1 || op2;

            bool op3;
            if(openCount>0){
                op3=help(s,index+1,openCount-1);
                ans=ans || op3;
            }
            return ans;
        }
        return false;
    }
    bool checkValidString(string s) {
        return help(s,0,0);
    }
};

// DP
class Solution {
public:
    bool help(string s, int index, int openCount, vector<vector<int> > &dp){
        int n=s.size();
        if(n==index){
            if(openCount==0){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[index][openCount]!=-1){
            return dp[index][openCount];
        }

        if(s[index]=='('){
            return dp[index][openCount]=help(s,index+1,openCount+1,dp);
        }
        else if(s[index]==')'){
            if(openCount==0){
                return dp[index][openCount]=false;
            }
            else{
                return dp[index][openCount]=help(s,index+1,openCount-1,dp);
            }
        }else if(s[index]=='*'){
            bool ans;
            bool op1=help(s,index+1,openCount,dp);
            bool op2=help(s,index+1,openCount+1,dp);

            ans=op1 || op2;

            bool op3;
            if(openCount>0){
                op3=help(s,index+1,openCount-1,dp);
                ans=ans || op3;
            }
            return dp[index][openCount]=ans;
        }
        return dp[index][openCount]=false;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int> > dp(n+5,vector<int>(n+5,-1));
        return help(s,0,0,dp);
    }
};

// Without DP
// First consider * as ( and 
// And then as ) and start from back
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();

        int openCount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                openCount++;
            }else if(s[i]==')'){
                if(openCount>0){
                    openCount--;
                }else{
                    return false;
                }
            }
        }

        int closedCount=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*'){
                closedCount++;
            }else if(s[i]=='('){
                if(closedCount>0){
                    closedCount--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};