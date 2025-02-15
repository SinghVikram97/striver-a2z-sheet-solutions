// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int n1=left.size();
        int n2=right.size();
        
        int i=0;
        int j=0;
        int k=0;
        
        int inversionCount=0;
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                k++;
                i++;
            }else{
                // left[i] > right[j]
                // IMP: Inversion caused by left[i]
                // and i<j
                // since both arrays sorted and we go to next element of right
                // for this element of right every element of left from i till end will be inversion
                inversionCount+=n1-i;
                arr[k]=right[j];
                k++;
                j++;
            }
        }
        
        while(i<n1){
            arr[k]=left[i];
            k++;
            i++;
        }
        
        while(j<n2){
            arr[k]=right[j];
            k++;
            j++;
        }
        
        return inversionCount;
    }
    int mergeSort(vector<int> &arr, int l,  int r){
        int n=r-l+1;
        
        if(n<=1){
            return 0;
        }
        
        int mid=(l+r)/2;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=l;i<=mid;i++){
            left.push_back(arr[i]);
        }
        
        for(int i=mid+1;i<=r;i++){
            right.push_back(arr[i]);
        }
        
        int leftCount = mergeSort(left, 0, left.size()-1);
        int rightCount = mergeSort(right, 0, right.size()-1);
        int mergeCount = merge(arr, left, right);
        
        return leftCount+rightCount+mergeCount;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};