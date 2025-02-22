// https://leetcode.com/problems/rotate-image/description/

// First solve: https://leetcode.com/problems/transpose-matrix/description/
/*
Transpose of matrix of dimension 3*2 is 2*3
*/

// Brute force with extra space
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int> > v(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j]=matrix[j][i];
            }
        }

        return v;
    }
};

// Without extra space if square matrix
/*
Mat:
1 2 3
4 5 6
7 8 9

Transpose
1 4 7
2 5 8
3 6 9

Mat:
01 02 03 04
05 06 07 08
09 10 11 12
13 14 15 16

Transpose
01 05 09 13
02 06 10 14
03 07 11 15
04 08 12 16

WE need to swap mat[i][j] and mat[j][i]

but we can't swap them twice if traverse whole matrix
we know if we are done with ith row then ith column numbers were swapped
for begin j for a given i with i+1
*/
class Solution {
public:
    vector<vector<int> > transposeSquare(vector<vector<int> > &matrix){
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        return matrix;
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        if(m==n){
            return transposeSquare(matrix);
        }

        vector<vector<int> > v(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j]=matrix[j][i];
            }
        }

        return v;
    }
};


// Now to rotate matrix by 90 degrees question since m==n
/*
Mat:
1 2 3
4 5 6
7 8 9

Transpose
1 4 7
2 5 8
3 6 9

90 degrees
7 4 1
8 5 2
9 6 3

We take transpose and reverse the rows
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};