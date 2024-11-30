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

        int ans=INT_MIN+4;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            int maxFreq=0;
            
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                maxFreq=max(maxFreq, mp[s[j]]);

                int subStringLength=j-i+1;

                int diffChars=subStringLength-maxFreq;

                if(diffChars<=k){
                    ans=max(ans, subStringLength);
                }
            }

        }

        return ans;
    }
};

// The problem can reduced to 
// "longest substring where (length - max occurrence) <= k"
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();

        int left=0;
        int right=0;

        unordered_map<char,int> mp;
        int maxFreq=0;

        int ans=INT_MIN+5;

        while(left<=right && right<n){
            mp[s[right]]++;
            maxFreq=max(maxFreq, mp[s[right]]);

            int substringLength=right-left+1;

            int diffChars=substringLength-maxFreq;

            if(diffChars<=k){
                // update ans
                ans=max(ans, substringLength);
                // expand window
                right++;
            }else{
                // >k 
                while(left<right && diffChars>k){
                    // shrink window
                    mp[s[left]]--;
                    left++;
                    
                    maxFreq=-1;
                    // update maxFreq
                    for(auto it:mp){
                        maxFreq=max(maxFreq, it.second);
                    }

                    substringLength=(right-left+1);
                    diffChars=substringLength-maxFreq;
                }

                // now window valid update ans
                ans=max(ans,substringLength);
                // expand window
                right++;
            }
        }
        return ans;
    }
};