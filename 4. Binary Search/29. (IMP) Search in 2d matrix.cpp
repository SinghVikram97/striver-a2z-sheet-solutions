// https://leetcode.com/problems/search-a-2d-matrix/description/

// m*n

// O(m*log(n))
class Solution {
public:
    bool binary_search(vector<int> &v, int target){
        int size=v.size();
        int start=0;
        int end=size-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(v[mid]==target){
                return true;
            }else if(target<v[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                return binary_search(matrix[i], target);
            }
        }

        return false;
    }
};

// O(log(m+n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int i=m-1;
        int j=0;

        while(i>=0 && j<n){
            if(matrix[i][j]==target){
                return true;
            }else if(target>matrix[i][j]){
                // move right
                j++;
            }else{
                // move up
                i--;
            }
        }

        return false;
    }
};