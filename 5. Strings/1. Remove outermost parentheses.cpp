// https://leetcode.com/problems/remove-outermost-parentheses/description/
class Solution {
public:
     string removeOuterParentheses(string S) {
        string res = "";
        stack<char> st;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '('){
                if(!st.empty()){
                    res += S[i];
                }
                
                st.push(S[i]);
            }else{
                st.pop();
                if(!st.empty()){
                    res += S[i];
                }
            }
        }
        
        return res;
    }
};