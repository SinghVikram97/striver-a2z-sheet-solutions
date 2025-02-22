// https://leetcode.com/problems/powx-n/description/
class Solution {
public:
    double myPow(double x, int n) {
       long long int nn = abs((long long int) n); // -ve has more range so can overflow during conversion
       double ans = powR(x,nn); 

       if(n<0){
         return 1/ans;
       }
       else{
        return ans;
       }
    }

    double powR(double x, long n){
        if(n==0){
            return 1;
        }
        if(n%2==0){
            return powR(x*x,n/2);
        }
        else{
            return x*powR(x,n-1);
        }
    }
};