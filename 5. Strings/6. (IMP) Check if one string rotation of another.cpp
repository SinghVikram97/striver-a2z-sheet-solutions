// https://leetcode.com/problems/rotate-string/description/

// every rotation of s will be present in string s+s so if goal one of the rotation it must be a substring of s+s
// remeber to check for length !
// otherwise it will fail for 
/*
s=aa
goal=a
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()==goal.length() && (s+s).find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};