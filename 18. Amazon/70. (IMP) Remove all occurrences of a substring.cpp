// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description
/*
Note that a new occurrence of pattern can appear if you remove an old one, 
For example, s = "ababcc" and pattern = "abc".

remove abc we get s=abc
now again we remove abc we get s=""
*/
// Using stack
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n1=s.length();
        int n2=part.length();

        stack<char> ms;

        for(int i=0;i<n1;i++){
            if(s[i]==part.back()){
                ms.push(s[i]);

                if(ms.size()<n2){
                    continue; // size less than pattern string
                }

                int j=n2-1;
                while(!ms.empty() && j>=0 && ms.top()==part[j]){
                    ms.pop();
                    j--;
                }
                if(j>=0){
                    for(int k=j+1;k<=n2-1;k++){
                        ms.push(part[k]);
                    }
                }
            }else{
                ms.push(s[i]);
            }
        }

        string ans="";
        while(!ms.empty()){
            ans=ms.top()+ans;
            ms.pop();
        }
        return ans;
    }
};


// Using find