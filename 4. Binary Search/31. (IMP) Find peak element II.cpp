// https://leetcode.com/problems/find-a-peak-element-ii/


// Solve this before: https://leetcode.com/problems/find-peak-element/description/
// WE can use the same logic to make it into a 1d array and solve it
// But to make it into a 1d array time taken would be O(m*n)

// We take 2 pointers start col and end col
// Now for the mid col we find the maximum element as it has highest chance of being a peak
// Now top and bottom already sorted for it since it is max element in that column

// See left and right is left is greater than this maximum element then move left
// Else move right

// for example when we move left, since the left element > max of col which is to the right so 
// in left col even if left element is not the max, lets say some other element is max
// so that max element will be greater than every element of right col
// so this way we maintain the algorithm
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int m=mat.size();
       int n=mat[0].size();

       int start=0;
       int end=n-1;

       while(start<=end){
            int mid=(start+end)/2;
            int rowNo;

            int maxi=-1;
            int index=0;

            for(int i=0;i<m;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    index=i;
                }
            }

            rowNo=index;

            int left=(mid-1)>=0 ? mat[rowNo][mid-1] : -1;
            int right=(mid+1)<n ? mat[rowNo][mid+1] : -1;

            int maxEle=mat[rowNo][mid];

            if(maxEle>left && maxEle>right){
                return {rowNo,mid};
            }else if(maxEle<left){
                // move left
                end=mid-1;
            }else{
                // move right
                start=mid+1;
            }
       } 

       return {-1,-1};
    }
};