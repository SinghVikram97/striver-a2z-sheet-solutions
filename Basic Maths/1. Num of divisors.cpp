// https://practice.geeksforgeeks.org/problems/count-digits5716/1

class Solution{
public:
    int evenlyDivides(int N){
      int number = N;
       int count=0;

       while(N){
          int digit = N%10;
          N=N/10;

          if(digit!=0 && number%digit==0){
            count++;
          }
       }

       return count;
    }
};