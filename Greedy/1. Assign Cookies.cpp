// https://leetcode.com/problems/assign-cookies/description/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());

        int ans=0;

        int i=0;
        int j=0;

        int m=g.size();
        int n=s.size();

        while(i<m && j<n){
            if(s[j]>=g[i]){
            //satisfied move both
            i++;
            j++;
            ans++;
            }
            else{
                // move child, make it small
                i++;
            }
        }
        return ans; 
    }
};