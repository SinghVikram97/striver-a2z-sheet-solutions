// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

// Brute force
// TC=O(26*n^2)
class Solution {
public:
    int beautySum(string s) {
        int n=s.length();

        int ans=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                // find most freq and least freq element
                int maxFreq=INT_MIN;
                int leastFreq=INT_MAX;
                for(auto it=mp.begin();it!=mp.end();it++){
                    maxFreq=max(maxFreq, it->second);
                    leastFreq=min(leastFreq, it->second);
                }

                ans=ans+(maxFreq-leastFreq);
            }
        }

        return ans;
    }
};
