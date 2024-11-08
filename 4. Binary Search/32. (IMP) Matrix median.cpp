// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Median is the middle element
// Elements before median = Elements after median

// Since total number of elements odd so 
// let's say m*n=15
// so 7 elements before median and 7 after

// 3 cases

// 1 2 5 7 8
// 1 2 5 5 8
// 1 5 5 7 8

// m*n=5/2= 2 elements before median

// if we only check elements < median
// in 1st case -> 2, 2nd -> 2, 3rd -> 1 but still 5 is median

// so we can't check for < we have to check for <=

// it means we are including median
// so for median the number of elements <= it will always be greater than m*n/2 
// 1st -> 3, 2nd -> 3, 3rd -> 3

// so just have to find 1st number from left for which elements less than equal to it are greater than m*n/2
class Solution{   
public:
    int upperBound(int target, vector<int> &v){
        int size=v.size();

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
    int help(int number, vector<vector<int> > &mat, int m, int n){
        // since every row sorted we can do binary search in every row to find elements less than equal to number

        // find upper bound for the num
        // 1 3 5 5 7 8
        // upper bound 5 -> index 3 -> ie. 4 elements
        int ans=0;
        for(int i=0;i<m;i++){
            ans=ans+(upperBound(number, mat[i])+1);
            
        }
        return ans;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int total=R*C;

        // 3*3=9/2=4 ie 4 elements smaller 4 bigger and median in middle
        int target=total/2;      

        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<R;i++){
            maxi=max(maxi, matrix[i][C-1]);
            mini=min(mini, matrix[i][0]);
        }
        
        int start=mini;
        int end=maxi;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;

            int smallerEqualElements = help(mid, matrix, R, C);

            if(smallerEqualElements>target){
                ans=mid;
                // move left we have to find first element
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};