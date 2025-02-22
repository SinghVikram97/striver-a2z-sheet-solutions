// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        int left=0;
        int right=0;

        unordered_set<int> ms;
        int ans=0;
        while(left<=right && right<n){
            if(ms.find(s[right])==ms.end()){
                // update ans
                ans=max(ans, right-left+1);
                // add in set
                ms.insert(s[right]);
                // increase window length
                right++;
            }else{
                // already seen this character remove its repeat from front
                while(left<right && s[left]!=s[right]){
                    ms.erase(s[left]);
                    left++;
                }

                // now s[left]==s[right]
                // so remove this from window
                ms.erase(s[left]);
                left++;
                
                // now we have a substring with no repeating characters 
                // so do the same thing
                // update ans
                ans=max(ans, right-left+1);
                // add in set
                ms.insert(s[right]);
                // increase window length
                right++;

            }
        }

        return ans;
    }
};