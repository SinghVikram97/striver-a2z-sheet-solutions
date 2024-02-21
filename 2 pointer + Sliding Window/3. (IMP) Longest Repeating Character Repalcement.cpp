// https://leetcode.com/problems/longest-repeating-character-replacement/
// Brute force
// see all substrings
// ABABBA k=2
// for substring BABB 
// how do we know if it is a valid substring
// freq(B) = 3, freq(A) = 1
// so we see the frequency of most frequent character
// and try to replace all other characters
// length of substring = 4 - freq(B) = 1 (Different characer) which is A
// Since 2 Different characters allowed it is a valid string

// TLE
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=-1;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            int maxFreq=0;
            for(int j=i;j<n;j++){
                // substring [i,j]
                mp[s[j]]++;
                maxFreq=max(maxFreq,mp[s[j]]);

                // check if its valid substring
                int substringLength=j-i+1;
                int diffCharacters=substringLength-maxFreq;
                if(diffCharacters<=k){
                    // valid
                    ans=max(ans,substringLength);
                }
            }
        }
        return ans;
    }
};

// 2 pointer - left and right
// if window is valid expand window
// if window not valid shrink window from left
// When is window valid
// if length of window - maximum freq of an element <= k
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=left;
        // window [left,right)
        int n=s.length();
        unordered_map<char,int> mp;
        int maxFreq=-1;
        int ans=-1;

        while(left < n && right < n){
            mp[s[right]]++;
            maxFreq=max(maxFreq,mp[s[right]]);
            right++;

            // check if window still valid
            int lengthWindow=right-left;
            
            if(lengthWindow-maxFreq<=k){
                // valid
                ans=max(ans,lengthWindow);
            }else{
                // shrink till window becomes valid
                while(left<n && lengthWindow-maxFreq>k){
                    mp[s[left]]--;
                    left++;
                    lengthWindow=right-left;
                    // update maxFreq
                    for(auto it:mp){
                        maxFreq=max(maxFreq,it.second);
                    }
                }
                // Update ans now that it is a valid window
                ans=max(ans,lengthWindow);
            }
        }
        return ans;
    }
};