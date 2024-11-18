// https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
public:
    void reverseString(string &s){
        int start=0;
        int end=s.length()-1;

        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        reverseString(s);
        int n=s.length();

        // skip starting white spaces
        int i=0;

        string temp="";
        string ans="";
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            reverseString(temp);
            ans+=temp;
            
            while(i<n && s[i]==' '){
                i++;
            }
            
            if(i<n){
                ans+=" ";
            }
        }
        return ans;
    }
};