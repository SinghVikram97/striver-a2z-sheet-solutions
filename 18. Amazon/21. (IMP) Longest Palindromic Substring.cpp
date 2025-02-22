// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string str) {
        int n=str.length();

        int maxLength=INT_MIN;
        int start=0;
        int end=0;

        for(int i=0;i<n;i++){
            // assuming str[i] is middle char
            int j=i; // takes care of single char as well otherwise we can start at j=i-1 k=i+1 but str[i] is palindrome in itself
            int k=i;

            // grow both sides assuming str[i] is middle char
            while(j>=0 && k<n){
                if(str[j]==str[k]){
                    int length=k-j+1;

                    if(length>maxLength){
                        maxLength=length;
                        start=j;
                        end=k;
                    }
                    j--;
                    k++;
                }else{
                    break;
                }
            }

            // assume str[i] is side char 
            // assume it to be left char

            j=i;
            k=i+1;

            while(j>=0 && k<n){
                if(str[j]==str[k]){
                    int length=k-j+1;

                    if(length>maxLength){
                        maxLength=length;
                        start=j;
                        end=k;
                    }
                    j--;
                    k++;
                }else{
                    break;
                }
            }
        }

        string ans="";
        for(int i=start;i<=end;i++){
            ans+=str[i];
        }

        return ans;
    }
};