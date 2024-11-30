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

