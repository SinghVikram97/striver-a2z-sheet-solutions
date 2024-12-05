// https://leetcode.com/problems/valid-parenthesis-string/description/

// Recursion - Wrong
// Because can't simply check for count equal
// Fails for ))((
class Solution {
public:
    bool helper(string &s, int index, int openCount, int closeCount){
        int n=s.length();

        if(index==n){
            return openCount==closeCount;
        }

        if(index==n){
            return false;
        }

        if(s[index]=='('){
            return helper(s, index+1, openCount+1, closeCount);
        }else if(s[index]==')'){
            return helper(s,index+1, openCount, closeCount+1);
        }else{
            // consider all 3 posibilities
            return helper(s,index+1,openCount,closeCount) || helper(s, index+1, openCount+1, closeCount) 
            || helper(s,index+1, openCount, closeCount+1);
        }
    }
    bool checkValidString(string s) {
        return helper(s,0,0,0);
    }
};

/*
If we encounter a closing bracket ')' opening count must be > 0
Since we can't close without opening first

So we keep tracking of openingCount
if we reach a closing bracket if openingCount>0 we decrement if its =0 we return false

incase of '*'
- empty string
- opening bracket -> openingCount++
- if openingCount>0 we can also consider it as closing bracket

base case if openingCount=0 return true
*/
class Solution {
public:
    bool helper(string &s, int index, int openCount){
        int n=s.length();

        if(index==n){
            return openCount==0;
        }

       
        if(s[index]=='('){
            return helper(s, index+1, openCount+1);
        }else if(s[index]==')'){
            if(openCount==0){
                return false;
            }else{
                return helper(s,index+1,openCount-1);
            }
        }else{
            bool op1=helper(s,index+1,openCount); // ""
            bool op2=helper(s,index+1,openCount+1); // "("

            bool op3=false;

            if(openCount>0){
                op3=helper(s,index+1,openCount-1); // ")"
            }

            return op1 || op2 || op3;
        }
    }
    bool checkValidString(string s) {
        return helper(s,0,0);
    }
};


// DP
class Solution {
public:
    bool helper(string &s, int index, int openCount, vector<vector<int> > &dp){
        int n=s.length();

        if(index==n){
            return openCount==0;
        }

        if(dp[index][openCount]!=-1){
            return dp[index][openCount];
        }
       
        if(s[index]=='('){
            return dp[index][openCount]=helper(s, index+1, openCount+1,dp);
        }else if(s[index]==')'){
            if(openCount==0){
                return dp[index][openCount]=false;
            }else{
                return dp[index][openCount]=helper(s,index+1,openCount-1,dp);
            }
        }else{
            bool op1=helper(s,index+1,openCount,dp); // ""
            bool op2=helper(s,index+1,openCount+1,dp); // "("

            bool op3=false;

            if(openCount>0){
                op3=helper(s,index+1,openCount-1,dp); // ")"
            }

            return dp[index][openCount]=(op1 || op2 || op3);
        }
    }
    bool checkValidString(string s) {
        vector<vector<int> > dp(s.length()+1, vector<int>(s.length()+1, -1));
        return helper(s,0,0,dp);
    }
};

// 2 Pass
/*
Approach: 
* There are more open parenthesis but we have enough '*' so we can balance the parenthesis with ')'
* There are more close parenthesis but we have enough '*' so we can balance the parenthesis with '('
* There are as many '(' than ')' so all parenthesis are balanced, we can ignore the extra '*'
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();

        // going from left to right consider * as (
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

        // Going from right to left consider * as )
        // reverse we can't an open bracket to left if no closed to the right
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