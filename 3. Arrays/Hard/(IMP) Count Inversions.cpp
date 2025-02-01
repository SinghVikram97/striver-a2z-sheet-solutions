// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//IMP: DO stackqueue/ monotonic stack / number of nge to right in that leetcode question

/*
In an array if x, y at index i,j

then if x>y and i<j then inversion

2, 9, 6
the pair of numbers (9, 6) is an inversion.


*/

// Brute Force
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

// Optimised using merge sort
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int i=0;
        int j=0;
        int k=0;
        
        int n1=left.size();
        int n2=right.size();
        
        int inversionCount=0;
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
                k++;
            }else{
                // it means left[i]>right[j]
                // and since it lies on left size so inversion
                // all remaining elements of left will also be greater than this right[j]
                // since left sorted remaining elements greater than left[i]
                inversionCount=inversionCount+(n1-i);
                arr[k]=right[j];
                j++;
                k++;
            }
        }
        
        while(i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k]=right[j];
            j++;
            k++;
        }
        
        return inversionCount;
    }
    int mergeSort(vector<int> &arr, int start, int end){
        if(start>=end){
            return 0; // single element in case =
        }
        
        int n=(end-start+1);
        
        int mid=(n-1)/2;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<=mid;i++){
            left.push_back(arr[i]);
        }
        
        for(int j=mid+1;j<n;j++){
            right.push_back(arr[j]);
        }
        
        // merge left and right
        int leftCount = mergeSort(left, 0, left.size()-1);
        int rightCount = mergeSort(right, 0, right.size()-1);
        
        // merge both sorted arrays
        int mergeCount = merge(arr, left, right);
        
        return leftCount+rightCount+mergeCount;
        
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};