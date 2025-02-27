// https://leetcode.com/problems/count-good-numbers/

// TLE

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n==1){
            return 5;
        }

        long long int A = 1000000007;
        long long int oddIndex = n/2;
        long long int evenIndex = n-(n/2);

        long long int evenTimes = 1;
        for(int i=0;i<evenIndex;i++){
            evenTimes=((evenTimes%A)*(5%A))%A;
        }

        long long int primeTimes = 1;
         for(int i=0;i<oddIndex;i++){
            primeTimes=((primeTimes%A)*(4%A))%A;
        }

        return ((evenTimes%A)*(primeTimes%A))%A;
    }
};

// Recursive,
// if n is even, n=0,2,4 -> dp[n]=dp[n-1]*4
// if n is odd , n=1,3,5, -> dp[n]=dp[n-1]*5

// TLE
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long int M = 1000000007;
        long long int ans = 5;

        if(n==1){
            return ans;
        }

        for(int i=2;i<=n;i++){
            if(i%2==0){
                ans = ((ans%M)*(4%M))%M;
            }
            else{
                ans = ((ans%M)*(5%M))%M;
            }
        }
        return ans;
    }
};