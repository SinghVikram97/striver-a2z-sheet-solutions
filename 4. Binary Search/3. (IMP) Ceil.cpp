// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int start=0, end=n-1;
        
        int floor=-1;
        int ceil=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==x){
                return {x,x};
            }else if(arr[mid]<x){
                floor=arr[mid];
                start=mid+1;
            }else{
                ceil=arr[mid];
                end=mid-1;
            }
        }
        
        return {floor,ceil};
    }
};