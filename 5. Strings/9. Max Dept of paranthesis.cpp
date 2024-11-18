// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
public:
    int maxDepth(string s) {
        int openCount=0;

        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openCount++;
                ans=max(ans, openCount);
            }else if(s[i]==')'){
                openCount--;
            }
        }

        return ans;
    }
};