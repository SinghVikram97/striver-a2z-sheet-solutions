// https://leetcode.com/problems/clear-digits/description/
class Solution {
public:
    string clearDigits(string s) {
        stack<char> ms;

        int n=s.length();

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                ms.pop();
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

// Using wall
// If encounter a digit do wall-- to remove character that you last included ie. closest to digit 
class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int wall=-1;

        for(int i=0;i<n;i++){
            if(!isdigit(s[i])){
                wall++;
                s[wall]=s[i];
            }else{
                if(wall>=0){
                    wall--;
                }
            }
        }
        return s.substr(0, wall+1); 
    }
};