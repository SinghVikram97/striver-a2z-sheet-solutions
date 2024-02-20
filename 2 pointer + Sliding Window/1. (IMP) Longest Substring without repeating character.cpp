// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// abccbcbb -> when i=a(0) and j=c(3) , we can start next substring at i=3 ie. just after duplicate
// abcbbcbb -> when i=a(0) and j=b(3), we can start next substring at i=2, just after duplicate b at i=1 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ms;
        int n=s.length();

        int i=0;
        int j=i; // [i,j) 
        int maxCount=0;
        while(i<n && j<n){
            // consider j in window
            if(ms.find(s[j])==ms.end()){
                ms.insert(s[j]);
                j++; // add j to window
                maxCount=max(maxCount,j-i);
            }
            else{
                cout<<s[i]<<endl;
                // duplicate 
                // remove from set
                // increase i till we find s[j]
                while(s[i]!=s[j]){
                    ms.erase(s[i]);
                    i++;
                }
                ms.erase(s[i]);
                i++;
                // j not changed as j was earlier not included due to duplicate
                // now it will be included in next iteration
            }
        }
        return maxCount;
    }
};

// instead of set we can store the indices of characters
// and if we find a duplicate we just move the start of window to duplicate index+i
// also while adding we just check that if character doesn't exists in map
// or if it exists its index is not in current range 
// ie. myMap[s[i]]<i 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mm;
        int n=s.length();

        int i=0;
        int j=i;
        int maxLength=0;
        while(i<n && j<n){
            if(mm.find(s[j])==mm.end() || mm[s[j]]<i){
                mm[s[j]]=j;
                j++;
                maxLength=max(maxLength,(j-i));
            }else{
                // move i to next index
                i=mm[s[i]]+1;
            }
        }
        return maxLength;
    }
};