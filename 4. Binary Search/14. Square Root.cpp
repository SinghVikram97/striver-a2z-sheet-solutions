// https://www.geeksforgeeks.org/problems/square-root/0
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // square root will be b/w 1 to n
        long long int start=1;
        long long end=n;
        
        long long ans;
        while(start<=end){
            long long mid=(start+end)/2;
            
            long long sqr=mid*mid;
            
            if(sqr==n){
                return mid;
            }else if(sqr>n){
                // move left
                end=mid-1;
            }else{
                // move right
                // mid*mid < n
                ans=mid; // incase it doesn't have perfect square
                start=mid+1;
            }
        }
        
        return ans;
    }
};