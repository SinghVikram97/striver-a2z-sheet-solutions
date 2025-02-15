// https://leetcode.com/problems/reverse-pairs/description/

// TLE using previous problem concept
/*
Here we can't do inversionCount+=n-i 
Because
let's say we are merging
[2,3,4] and [1,5]

now i=0, j=0
left[i]>right[j]

now we check condition 2*right[i]=2 which is equal to left[i]
so we don't include inversions including 1
ie. we miss out on 3,1 and 4,1 
but in prev problem we won't have, here we don't have that guarantee 
so we add a loop instead
*/
class Solution {
public:
    int merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int n1=left.size();
        int n2=right.size();
        
        int i=0;
        int j=0;
        int k=0;
        
        int inversionCount=0;
        
        while(i<n1 && j<n2){
            if(left[i]<right[j]){
                arr[k]=left[i];
                k++;
                i++;
            }else{
                // check if left[i]*2 > right[j]
                for(int m=i;m<n1;m++){
                    if(ceil(left[m]/2.0)>right[j]){
                        inversionCount++;
                    }
                }

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
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};


// We find inversion count separately before merging both but make use of the fact that they are sorted
class Solution {
public:
    void merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int n1=left.size();
        int n2=right.size();
        
        int i=0;
        int j=0;
        int k=0;
        
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                k++;
                i++;
            }else{
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

        // Both left and right are sorted
        // We want left[i]>2*right[j]
        int i=0;
        int j=0;
        int reversePairCount=0;

        // for each left[i] calculate numbers greater than 2*right[j]
        // here we increase j till the index it is valid then we get the required number
        // for the next left[i] j will already be at previous index but we are sure left[i] will be greater than
        // all the 2*right[j] which got increased by previous left[i]
        while(i<left.size()){
            while(j<right.size() && left[i]>2*(long long)right[j]){
                j++;
            }
            reversePairCount+=j;
            i++;
        }

        merge(arr, left, right);
        
        return leftCount+rightCount+reversePairCount;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};