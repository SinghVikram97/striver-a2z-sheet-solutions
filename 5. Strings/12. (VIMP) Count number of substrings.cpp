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
We find count of substrings with atmost k distinct characters ie. if k=3 we find substring with 1 distinct char, 2 distinct char, 3 distinct char
Then we find substrings with atmost k-1 distinct characters

Then substrings with exactly k distinct characters = atmost(k)-atmost(k-1)

*/


// Longest substring with atmost k distinct characters
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
        
        if(mp[str[end]]==1){
            countDistinct++;
        }

        if(countDistinct<=k){
            ans=max(ans,end-start+1);
        }else if(countDistinct>k){
            while(start<=end && countDistinct!=k){
                mp[str[start]]--;
                if(mp[str[start]]==0){
                    countDistinct--;
                }
                start++;
            }

            if(start>end){
                break;
            }

            // calculate if countDistinct becomes k with this new end
            if(countDistinct==k){
                ans=max(ans, end-start+1);
            }
        }

        end++;
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
class Solution
{
  public:
    long long int atMostK(string &s, int k){
        if(k==0){
            return 0;
        }
        int start=0;
        int end=0;
        int n=s.length();
        unordered_map<char,int> mp;
        int countDistinct=0;
        
        long long int ans=0;
        while(start<=end && end<n){
            mp[s[end]]++;
            
            if(mp[s[end]]==1){
                countDistinct++;
            }
            
            if(countDistinct<=k){
                ans=ans+(end-start+1); 
            }else if(countDistinct>k){
               // move start right
               while(start<=end && countDistinct!=k){
                   mp[s[start]]--;
                   if(mp[s[start]]==0){
                       countDistinct--;
                   }
                   start++; 
               }
               
               if(start>end){
                   break;
               }
               
               if(countDistinct==k){
                   // add ans for this valid window since we increment end in next statement
                   // but we need to account for this window since it becomes valid now 
                   ans=ans+(end-start+1);
               }
            }
            
            end++; // move right
        }
        
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return atMostK(s,k)-atMostK(s,k-1);
    }
};