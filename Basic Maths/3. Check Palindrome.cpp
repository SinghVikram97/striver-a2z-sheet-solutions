// https://leetcode.com/problems/palindrome-number/

class Solution {
public:

    long int reverse(int x) {
        long int revNum = 0;
        while(x){
            int digit=x%10;
            x = x / 10;
            revNum = (revNum*10) + digit;
        }
        return revNum;
    }

    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int y = reverse(x);
        if(y==x){
            return true;
        }else{
            return false;
        }
    }
};