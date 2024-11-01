// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        int start=0;
        int end=n-1;
        
        int floor=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(v[mid]==x){
                return mid;
            }else if(v[mid]<x){
               floor=mid;
               start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return floor;
    }
};