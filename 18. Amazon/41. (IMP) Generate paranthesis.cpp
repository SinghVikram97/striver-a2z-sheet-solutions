// https://leetcode.com/problems/generate-parentheses/description/
class Solution {
public:
    void generate(int n, int i, int countLeft, int countRight, string cur, vector<string> &ans) {

        if(i==2*n){
            ans.push_back(cur);
            return;
        }

        if(countLeft<n){
            generate(n,i+1,countLeft+1,countRight,cur+"(",ans);
        }

        if(countLeft>countRight){
            generate(n,i+1,countLeft,countRight+1,cur+")",ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n,0,0,0,"",ans);
        return ans;
    }
};