// https://leetcode.com/problems/assign-cookies/description/

/*
1. Smallest greed satisfy with smallest cookie
2. Also try to satisfy smallest greed first more probaility of it getting satisfied - greedy
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int numChildren=g.size();
        int numCookies=s.size();

        if(numChildren==0 || numCookies==0){
            return 0;
        }

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0;
        int j=0;

        int ans=0;
        while(i<numChildren && j<numCookies){
            // satisfy first child with cookie
            int greed=g[i];

            while(j<numCookies && s[j]<greed){
                j++;
            }

            if(j==numCookies){
                // can't satisfy this child other children after this has higher greed
                // So can't satifsy them as well so return
                return ans;
            }else{
                // give this child jth cookie
                ans++;
                // try next child
                i++;
                // start from next cookie
                j++;
            }
        }
        return ans;
    }
};