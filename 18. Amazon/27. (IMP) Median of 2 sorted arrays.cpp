// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    int upperBound(int target, vector<int> &v){
        int size=v.size();
        if(size==0){
            return -1;
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int i=0;
        int j=0;

        int size=n1+n2;
        
        if(size%2==0){
            int a = kthElement((size/2), nums1, nums2);
            int b = kthElement((size/2)+1, nums1, nums2);
            return (a+b)/2.0;
        }else{
            return kthElement((size/2)+1, nums1, nums2);
        }
    }
};