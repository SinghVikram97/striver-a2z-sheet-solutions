// https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1


// GCD(a,b) = GCD(a%b,b), a>b
class Solution {
  public:

    long long gcd(long long A, long long B) {
      while(A!=0 && B!=0){
          if(A>=B){
            A=A%B;
          }else{
            B=B%A;
          }
      }
      
      if(A==0){
          return B;
      }
      return A;
    }

    vector<long long> lcmAndGcd(long long A , long long B) {
        long long gcdAns = gcd(A,B);
        long long lcmAns = (A*B)/(gcdAns);
        return {lcmAns, gcdAns};
    }
};