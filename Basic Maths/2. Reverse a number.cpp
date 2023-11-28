// https://leetcode.com/problems/reverse-integer/

// basic
class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while(x){
            int digit=x%10;
            x = x / 10;
            revNum = (revNum*10) + digit;
        }
        return revNum;
    }
};

// return 0 if overflow
class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while(x){
            int digit=x%10;
            x = x / 10;
            
            if(((INT_MAX-1)/10)<revNum){
                return 0;
            }

            if(((INT_MIN)/10)>revNum){
                return 0;
            }


            revNum = (revNum*10) + digit;
        }
        return revNum;
    }
};