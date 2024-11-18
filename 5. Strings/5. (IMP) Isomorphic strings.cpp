// https://leetcode.com/problems/isomorphic-strings/description/ 

// we have to check one to one mapping b/w s[i] and t[i]
// ie. each char in s[i] maps to one in t[i]
// each char in t[i] maps to one in s[i]

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> ms;

        if(s.length()!=t.length()){
            return false;
        }else{
            int n=s.length();
            for(int i=0;i<n;i++){
                if(mp.find(s[i])==mp.end()){
                    // s[i] not mapped to any char 
                    
                    // check if t[i] already assigned to some other char
                    if(ms.find(t[i])!=ms.end()){
                        // already assigned 
                        return false;
                    }

                    // map s[i] to t[i]
                    mp[s[i]]=t[i];
                    ms.insert(t[i]);
                }else{
                    // already assigned s[i]<->t[i]
                    // check if assigned char same
                    if(mp[s[i]]!=t[i]){
                        return false;
                    }
                }
            }
            return true;
        }
    }
};

// Another approach
// paper  title
// we store last seen index for each character and they should be same

// for example mp[p]=0 and mp[t]=0 at i=2
// if there was some other char in place of p or t then its last seen character would have been different

// we store last index by 1 based indexing to avoid index 0 as false
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2; // initialized to 0 by default

        if(s.length()!=t.length()){
            return false;
        }else{
            int n=s.length();
            for(int i=0;i<n;i++){
               if(mp1[s[i]]==mp2[t[i]]){
                    mp1[s[i]]=i+1;
                    mp2[t[i]]=i+1;
               }else{
                 return false;
               }
            }
            return true;
        }
    }
};