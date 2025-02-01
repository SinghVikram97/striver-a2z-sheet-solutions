// https://leetcode.com/problems/valid-parentheses/description/
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> ms;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                ms.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(!ms.empty() && ms.top()=='('){
                        ms.pop();
                    }else{
                        return false;
                    }
                }
                else if(s[i]=='}'){
                    if(!ms.empty() && ms.top()=='{'){
                        ms.pop();
                    }else{
                        return false;
                    }
                }
                else if(s[i]==']'){
                    if(!ms.empty() && ms.top()=='['){
                        ms.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(!ms.empty()){
            return false;
        }
        return true;
    }
};