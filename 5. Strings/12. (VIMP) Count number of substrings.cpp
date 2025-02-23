// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1


// TC -> Brute force O(n2logn)
class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	int n=s.length();
    	
    	long long int ans=0;
    	for(int i=0;i<n;i++){
    	    unordered_set<char> ms;
    	    for(int j=i;j<n;j++){
    	        ms.insert(s[j]);
    	        if(ms.size()==k){
    	            ans++;
    	        }
    	    }
    	}
    	return ans;
    }
};

/*
Count distinct characters in substring of length k starting at each index

If this k length substring has distinct characters 
= k (longer strings can also have k distinct characters)
< k (longer strings can also have k distinct characters)
> k (longer string CAN't have k distinct characters)
*/
class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	int n=s.length();
    	
    	long long int ans=0;
    	for(int i=0;i<=n-k;i++){
    	    // fetch k length substring start from ith index
    	    string temp=s.substr(i, k);
    	    
    	    unordered_set<char> ms;
    	    
    	    for(int j=0;j<k;j++){
    	        ms.insert(temp[j]);
    	    }
    	       
    	    int countDistinct=ms.size();
    	    
    	    if(countDistinct>k){
    	        continue;
    	    }else{
    	        if(countDistinct==k){
    	            ans++;
    	        }
    	        // longer strings
    	        for(int j=i+k;j<n;j++){
    	            ms.insert(s[j]);
    	            
    	            if(ms.size()==k){
    	                ans++;
    	            }else if(ms.size()>k){
    	                break;
    	            }
    	        }
    	    }
    	}
    	return ans;
    }
};

// Sliding window
/*
Since finding count of substrings with exact k distinct characters is tough using sliding window

If it was length of longest substring then easy

We find count of substrings with atmost k distinct characters ie. if k=3 we find substring with 1 distinct char, 2 distinct char, 3 distinct char
Then we find substrings with atmost k-1 distinct characters

Then substrings with exactly k distinct characters = atmost(k)-atmost(k-1)

*/


// Longest substring with atmost k distinct characters
// https://www.naukri.com/code360/problems/distinct-characters_2221410
#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int n=str.length();

    int start=0;
    int end=0;

    int countDistinct=0;

    unordered_map<char,int> mp;

    int ans=0;
    while (start <= end && end < n) {
        mp[str[end]]++;
        
        // Check if newly included character so increment count of distinct characters
        if(mp[str[end]]==1){
            countDistinct++;
        }

        if(countDistinct<=k){
            ans=max(ans,end-start+1);
            end++;
        }else if(countDistinct>k){
            while(start<=end && countDistinct!=k){
                mp[str[start]]--;
                if(mp[str[start]]==0){
                    countDistinct--;
                }
                start++;
            }

            if(start>end && start<n){
                // start new window
                end=start;
                countDistinct=1;
                mp[str[end]]=1;
                if(countDistinct==k){
                    ans=max(ans,end-start+1);
                }
            }else if(countDistinct==k){
                ans=max(ans, end-start+1);
                end++;
            }else{
                // < k
                end++;
            }
        }
    }

    return ans;
}


// Count substrings with exactly k distinct characters

// for each valid window start ------ end
// add end-start+1 into ans 
/*
a a b a
0 1 2 3
let's say start at 0 and ending at 3

now if it is a valid window then every substring ending at index 3 would have atmost k distinct characters and not more
ie. aaba, aba, ba, a

so we add 3-0+1=4

*/
class Solution {
  public:
    int atMost(string &s, int k){
        int n=s.length();
        
        if(k==0){
            return 0;
        }
        
        unordered_map<char,int> freq;
        int countDistinct=0;
        
        int left=0;
        int right=0;
        
        int ans=0;
        
        while(left<=right && right<n){
            freq[s[right]]++;
            
            // newly included
            if(freq[s[right]]==1){
                // increase count distinct
                countDistinct++;
            }
            
            if(countDistinct<=k){
                ans=ans+(right-left+1);
                right++;
            }else{
                // > k
                while(left<=right && countDistinct!=k){
                    freq[s[left]]--;
                    if(freq[s[left]]==0){
                        countDistinct--;
                    }
                    left++;
                }
                
                // if not possible
                if(left>right){
                    // start new window
                    right=left;
                    freq[s[right]]=1;
                    countDistinct=1;
                    if(countDistinct==k){
                        ans=(right-left+1);
                    }
                }else if(countDistinct==k){
                    // managed to bring it to k
                    ans=ans+(right-left+1);
                    right++;
                }
            }
        }
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        return atMost(s, k) - atMost(s, k-1);
    }
};