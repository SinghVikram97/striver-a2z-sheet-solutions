// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.length();

        int start=0;
        int end=n-1;
        int ans=0;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else{
                // find element equal to s[start]
                int index=-1;
                for(int i=end-1;i>start;i--){
                    if(s[i]==s[start]){
                        index=i;
                        break;
                    }
                }

                // swap and bring s[index] to s[end]
                if(index==-1){
                    // s[start] will be mid element in palindrome
                    // push it to right
                    swap(s[start], s[start+1]);
                    ans++;
                }else{
                    for(int i=index;i<end;i++){
                        swap(s[i], s[i+1]);
                        ans++;
                    }
                    start++;
                    end--;
                }
            }
        }
        return ans;
    }
};