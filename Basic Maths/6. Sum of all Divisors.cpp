// https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

// Brute Force
class Solution
{
public:

    long long sumOfDivisor(int num) {
        long long int sum=0;
        for(int i=num;i>=1;i++){
            if(num%i==0){
                sum+=i;
            }
        }
        return sum;
    }
    long long sumOfDivisors(int N)
    {
        long long int ans=0;
        for(int i=1;i<=N;i++){
            ans+=sumOfDivisor(i);
        }
        return ans;
    }
};

// sqrt(n)*sqrt(n) = n
// divisors occur in pair
// a*b=n then a, b divisor of n
class Solution
{
public:

    long long sumOfDivisor(int num) {
        long long int sum=0;
        for(int i=1;(i*i)<=num;i++){
            if(num%i==0){
                sum+=i;
                sum+=num/i;
            }
        }
        return sum;
    }
    long long sumOfDivisors(int N)
    {
        long long int ans=0;
        for(int i=1;i<=n;i++){
            ans+=sumOfDivisor(i);
        }
        return ans;
    }
};

// More optimised
// N=4
// 1 will appear 1 time in F(1), F(2), F(3), F(4)
// 2 will appear 2 times, once in F(2) and once in F(4)

// So largest multiple of a number(i) <= N times it will appear
// so N/i = number of times a number will appear
// so sum = N/i * i
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long int ans=0;
        for(int i=1;i<=N;i++){
            ans+=(N/i)*i;
        }
        return ans;
    }
};