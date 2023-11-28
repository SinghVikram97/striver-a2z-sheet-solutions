// https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1


// Brute Force
class Solution {
  public:
    string armstrongNumber(int n){
        int temp = n;
        int ans=0;
        while(temp){
            int lastDigit=temp%10;
            ans=ans+(lastDigit*lastDigit*lastDigit);
            temp=temp/10;
        }
        if(ans==n){
            return "Yes";
        }else{
            return "No";
        }
    }
};