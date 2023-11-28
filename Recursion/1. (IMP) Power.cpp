// https://leetcode.com/problems/powx-n/

// Basic - TLE - O(N)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
       
        for(long int i=1;i<=abs(n);i++){
                ans=ans*x;
        }
    
        if(n<0){
            return 1/ans; // we calculate x^n we need to calculate x^(-n) = 1/x^n
        }
        return ans;
        
    }
};

// Binary Exponentiation 
// 2^10 = 4^5 
// 4^5 = 4*4^4
// 4^4 = 16^2
// 16^2 = 256^1
// 256^1 = 256 * 256^0 

// f(a,n) =
//  if n%2==0 , f(a*a,n/2)
//  if n%2==1, a*f(a,n-1)

// Recursive
class Solution {
public:
    double myPow(double x, int n) {
       long nn = abs(n); // -ve has more range so can overflow during conversion
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

// Using Binary Exponentiation
class Solution {
public:
    long long int M = 1000000007;
    int countGoodNumbers(long long n) {
        long long int ans = 5;

        if(n==1){
            return ans;
        }

        long long int powerOf4 = fastPow(4,n/2)%M;
        long long int powerOf5 = fastPow(5,n-n/2)%M;

        return ((powerOf4%M)*(powerOf5%M))%M;
    }

    long long int fastPow(long long int x,long long int n){
        if(n==0){
            return 1;
        }
        if(n%2==0){
            return fastPow(((x%M)*(x%M))%M,n/2);
        }
        else{
            return ((x%M)*(fastPow(x,n-1)%M))%M;
        }
    }
};