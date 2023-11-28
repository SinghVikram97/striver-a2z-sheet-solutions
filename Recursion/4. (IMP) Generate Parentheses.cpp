// https://leetcode.com/problems/generate-parentheses/

// parentheses -> ()
// n=1 , 
// n=2, ()(), (())

// length will be 2*n (each parentheses made of 2 brackets )

/*

if( i == 2*n) {
    add to ans
}
//recursive case
add (s+ “(“, i+1)
add (s+ “)", i+1)


// But need to be balanced so need to add constraints 
// ()) not balanced

// when can we add '(' till count of '(' <=n 
// when can we add ')' , only when count of '(' > count of ')'
// ex. (( -> can add  , () -> can't add, ()) -> can't add
// first character needs to be '(' will be automatically handled by above 2 conditions

*/


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