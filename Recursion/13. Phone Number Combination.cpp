// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

    void backtrack(string digits, int index, unordered_map<char,string> myMap, string currentString, vector<string> &ans) {
        if(index==digits.size()) {
            ans.push_back(currentString);
            return;
        }

        // digits[index] for ex is 3 , traverse and pick among d,e,f
        string choices = myMap[digits[index]];

        for(int i=0;i<choices.length();i++){
            backtrack(digits,index+1,myMap,currentString+choices[i],ans);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits==""){
            return {};
        }

        unordered_map<char,string> myMap;
        myMap['2']="abc";
        myMap['3']="def";
        myMap['4']="ghi";
        myMap['5']="jkl";
        myMap['6']="mno";
        myMap['7']="pqrs";
        myMap['8']="tuv";
        myMap['9']="wxyz";

        vector<string> ans;
        backtrack(digits, 0, myMap, "", ans);
        
        return ans;
    }
};