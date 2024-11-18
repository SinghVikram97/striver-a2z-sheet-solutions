// https://leetcode.com/problems/longest-palindromic-substring/description/

// Each character in string can be a middle character or part of palindrome if even length

// ie. aba or abba [with respect to b]

/*
Time complexity: O(n^2)

There are 2n−1=O(n) centers. For each center, we call expand, which costs up to O(n).

Although the time complexity is the same as in the DP approach, the average/practical runtime of the algorithm is much faster.
This is because most centers will not produce long palindromes, so most of the O(n) calls to expand will cost far less than n iterations.

The worst case scenario is when every character in the string is the same.
*/
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