// https://leetcode.com/problems/palindrome-partitioning/

// Time complexity -> 2^n-1
class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;

        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void backtrack(string s, int index, vector<string> currentArray, vector<vector<string> > &ans){
        if(index==s.length()){
            ans.push_back(currentArray);
            return;
        }   

        // Can partition the string at any place ie.
        // ex "aaba" -> a|aba , aa|ba , aab|a , aaba 
        // check if left parition palindrome and proceed where can we parition next to make right palindrome if possible

        string temp="";
        for(int i=index;i<s.length();i++){
            temp+=s[i]; // will hold a,aa,aab,aabc in respective iterations
            if(isPalindrome(temp)){
                currentArray.push_back(temp);
                backtrack(s,i+1,currentArray,ans);

                // backtrack
                currentArray.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        backtrack(s,0,{},ans);
        return ans;
    }
};