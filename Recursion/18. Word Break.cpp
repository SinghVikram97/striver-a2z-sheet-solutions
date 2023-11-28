// https://leetcode.com/problems/word-break/

// Approach 1 - TLE
class Solution {
public:

    bool backtrack(string s, int start, unordered_set<string> &dict) {
        if(start==s.length()) {
            return true;
        }

        // partition and see if it exits in dict
        string currentPartition="";
        for(int i=start;i<s.length();i++){
            currentPartition+=s[i];

            if(dict.find(currentPartition)!=dict.end()){
                if(backtrack(s,i+1,dict)){
                    return true;
                }
            }
        }

        return false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }

        return backtrack(s,0,dict);

    }
};

// Approach 2 - DP Memo
class Solution {
public:

    bool backtrack(string s, int start, unordered_set<string> &dict, vector<int> &dp) {
        if(start==s.length()) {
            return true;
        }

        if(dp[start]!=-1){
            return dp[start];
        }

        // partition and see if it exits in dict
        string currentPartition="";
        for(int i=start;i<s.length();i++){
            currentPartition+=s[i];

            if(dict.find(currentPartition)!=dict.end()){
                if(backtrack(s,i+1,dict,dp)==true){
                    dp[start]=1;
                    return true;
                }
            }
        }

        return dp[start]=0;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }

        vector<int> dp(s.length(),-1);

        return backtrack(s,0,dict,dp);

    }
};