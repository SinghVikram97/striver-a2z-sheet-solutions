// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// Brute force - TLE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        int ans=0;
        for(int i=0;i<n;i++){
            int aC=0;
            int bC=0;
            int cC=0;

            for(int j=i;j<n;j++){
                if(s[j]=='a'){
                    aC++;
                }else if(s[j]=='b'){
                    bC++;
                }else{
                    cC++;
                }

                if(aC>=1 && bC>=1 && cC>=1){
                    ans+=n-j;
                    break;
                }
            }
        }
        return ans;
    }
};

// Extend same concept to sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        int left=0;
        int right=0;

        unordered_map<char,int> ms;
        int ans=0;
        while(left<=right && right<n){
            ms[s[right]]++;

            if(ms.size()==3){
                // every substring containing [left,right] where right can go from [right,n]
                // will have 3 characters atleast
                ans=ans+(n-right); // same as n-j in brute force solution

                // shorten window
                while(left<right && ms.size()==3){
                    ms[s[left]]--;
                    if(ms[s[left]]==0){
                        ms.erase(s[left]);
                    }
                    left++;

                    // ans for this new window if still satisfies the condition
                    if(ms.size()==3){
                        ans=ans+(n-right);
                    }
                }

                // extend window now since ms.size()<3
                right++;

            }else{
                // need to extend window to get all 3 characters
                right++;
            }


        }
        return ans;
    }
};

// Even more optimized can be that we directly move to the leftMost last seen among a,b,c
// And add ans for skipping those indexes instead of doing below
/*
while(left<right && ms.size()==3){
    ms[s[left]]--;
    if(ms[s[left]]==0){
        ms.erase(s[left]);
    }
    left++;

    // ans for this new window if still satisfies the condition
    if(ms.size()==3){
        ans=ans+(n-right);
    }
}
*/
/*
Example:
a a a b c a b c
0 1 2 3 4 5 6 7

left at 0
right at 4 
we satisfy condition
now we can move directly to last seen of a + 1 ie. 3 since every a will satisfy this condition

ans=ans+(n-right)
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        int left=0;
        int right=0;

        unordered_map<char,int> ms; // store last seen
        int ans=0;
        while(left<=right && right<n){
            ms[s[right]]=right; // update last seen

            if(ms.size()==3){
                // update ans
                // find leftmost last seen
                int aSeen=ms['a'];
                int bSeen=ms['b'];
                int cSeen=ms['c'];

                int newLeft=min({aSeen, bSeen, cSeen});

                if(newLeft==aSeen){
                    ms.erase('a');
                }else if(newLeft==bSeen){
                    ms.erase('b');
                }else{
                    ms.erase('c');
                }

                ans=ans+((n-right)*(newLeft-left+1));

                left=newLeft+1; 
                right++; // current right won't satisfy the condition and we can't include it twice
            }else{
                // need to extend window to get all 3 characters
                right++;
            }


        }
        return ans;
    }
};