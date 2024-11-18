// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

/*

[2,3,6,7,9] and [1,4,8,10] and k=5
Ans=6
[1,2,3,4,6,7,8,9,10] elements < = 6 are 5

[6,6,6,7,9] and [1,4,8,10] and k=5
[1,4,6,6,6,7,8,9,10] elements < = 6 are 5

So elements <= X will always be atleast 5 (can me more as well in the above example if there are more 6s)

First element or leftmost element which has elements <= it as atleast k

Find elements <= using upper bound
*/

// TC -> O(log(max−min)×(logN+logM))
class Solution {
  public:
  int upperBound(int target, vector<int> &v){
        int size=v.size();
        if(size==0){
            return -1; // returns index
        }

        int start=0;
        int end=size-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(v[mid]<=target){
                ans=mid;
                // move further right
                start=mid+1;
            }else{
                // move left
                end=mid-1;
            }
        }
        return ans;
    }
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        
        // kth element will lie b/w minimum and maximum number
        int mini1=n1 ? arr1[0] : INT_MAX;
        int mini2=n2 ? arr2[0] : INT_MAX;
        
        int maxi1=n1 ? arr1[n1-1] : INT_MIN;
        int maxi2=n2 ? arr2[n2-1] : INT_MIN;
        
        int start=min(mini1, mini2);
        int end=max(maxi1,maxi2);
        
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            int up1=upperBound(mid, arr1) + 1; // index->3 elements->4
            int up2=upperBound(mid, arr2) + 1;
            
            if(up1+up2>=k){
                ans=mid;
                end=mid-1; // leftmost
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};