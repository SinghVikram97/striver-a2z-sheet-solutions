// https://www.geeksforgeeks.org/problems/merge-sort/1

// 0, 1, 2, 3, 4 n=5 5/2 = 2 left=[0,1,2] right = [3,4]

// 0, 1, 2, 3  n=4 4/2 = 2 left=[0,1,2] right=[3] not correct

/*
So mid = n-1 / 2
and left from 0 to mid
and right from mid+1 till n-1
*/

class Solution {
  public:
    void merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int i=0;
        int j=0;
        int k=0;
        
        int n1=left.size();
        int n2=right.size();
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
                k++;
            }else{
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
    }
    void mergeSort(vector<int>& arr, int l, int r) {
       if(l>=r){
           return;
       }
       
       int n=r-l+1; 
       
       int mid=(n-1)/2;
       
       vector<int> left;
       vector<int> right;
       
       for(int i=l;i<=mid;i++){
           left.push_back(arr[i]);
       }
       
       for(int j=mid+1;j<=r;j++){
           right.push_back(arr[j]);
       }
       
       // sort left and right
       mergeSort(left, 0, left.size()-1);
       mergeSort(right, 0, right.size()-1);
       
       // merge both arrays
       merge(arr, left, right);
    }
};

// Or use (l+r)/2 as mid
class Solution {
  public:
    void merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int i=0;
        int j=0;
        int k=0;
        
        int n1=left.size();
        int n2=right.size();
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
                k++;
            }else{
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
    }
    void mergeSort(vector<int>& arr, int l, int r) {
       if(l>=r){
           return;
       }
       
       int mid=(l+r)/2;
       
       vector<int> left;
       vector<int> right;
       
       for(int i=l;i<=mid;i++){
           left.push_back(arr[i]);
       }
       
       for(int j=mid+1;j<=r;j++){
           right.push_back(arr[j]);
       }
       
       // sort left and right
       mergeSort(left, 0, left.size()-1);
       mergeSort(right, 0, right.size()-1);
       
       // merge both arrays
       merge(arr, left, right);
    }
};