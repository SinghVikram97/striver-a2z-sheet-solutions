// https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n=str.size();

        int minSize=INT_MAX-5;
        for(int i=0;i<n;i++){
            int len=str[i].length();
            minSize=min(minSize, len);
        }

        int i=0;
        string ans="";
        while(i<minSize){
            char ch=str[0][i];
            for(int j=1;j<n;j++){
                if(str[j][i]!=ch){
                    return ans;
                }
            }
            cout<<endl;
            ans+=ch;
            i++;
        }

        return ans;
    }
};