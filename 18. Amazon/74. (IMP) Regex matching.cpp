// https://leetcode.com/problems/regular-expression-matching/description/


// * means match prev character 0 or more times
/*
example aab matches with c*a*b
because
* means match c zero or more times so we match zero times
then match a
then match b one time
*/
class Solution {
public:
    bool match(string &s, int i, string &p, int j){
        int n1=s.length();
        int n2=p.length();

        // if pattern finished string should be finished
        if(j==n2){
            return i==n1; 
        }

        // if pattern remaining and string finished that is possible
        // if we have * remaining
        if(p[j+1]=='*'){
            bool takeZeroTimes = match(s, i, p, j+2); // ignore *
            if(takeZeroTimes){
                return true;
            }

            // try with one or more times
            if(i<n1 && (s[i]==p[j] || p[j]=='.')){
                return match(s, i+1, p, j);
            }
        }else{
            if(i<n1){
                if(s[i]==p[j] || p[j]=='.'){
                    return match(s, i+1, p, j+1);
                }
            }
        }

        return false;
    }
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
};

// Now just memoize it with 2d dp