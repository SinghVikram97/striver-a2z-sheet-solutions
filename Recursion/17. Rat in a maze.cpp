// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// 1 - it can travel
// 0 - blocked
// start from 0,0 and need to reach N-1,N-1

class Solution{

    public:
    void backtrack(vector<vector<int> > &mat, int n, int i,int j, string currentPath, vector<string> &ans) {

        if(i==n-1 && j==n-1){
            if(mat[i][j]==1){
                ans.push_back(currentPath);
            }
            return;
        }

        if(i<0 || i>=n || j<0 || j>=n){
            return;
        }

        // if blocked can't go through- can't be in path
        if(mat[i][j]==0){
            return;
        }

        // include in path - block it (use block as visited)
        mat[i][j]=0;

        // travel to all 4 directions
        
        // up - i-1,j
        backtrack(mat, n, i-1 ,j, currentPath+"U", ans);
        // down- i+1, j
        backtrack(mat, n, i+1 ,j, currentPath+"D", ans);
        // left - i, j-1
        backtrack(mat, n, i ,j-1, currentPath+"L", ans);
        // right, i, j+1
        backtrack(mat, n, i ,j+1, currentPath+"R", ans);

        // backtrack - mark unvisited
        mat[i][j]=1;


    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        backtrack(m, n, 0 ,0, "", ans);
        return ans;
    }
};