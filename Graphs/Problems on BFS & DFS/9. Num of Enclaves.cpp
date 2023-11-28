// https://leetcode.com/problems/number-of-enclaves/

// Need to reach boundary 1
// Start DFS from boundary 1 to connected 1s, mark them visited
// The unvisited 1s would be the ones from where we can't reach the boundary

class Solution {
public:

    vector<vector<int> > dir = { {-1,0} , {1,0}, {0,-1}, {0,1} };

    void dfsUtil(int startI,int startJ,int m,int n, vector<vector<int> > &grid, vector<vector<bool> > &visited) {
        visited[startI][startJ]=true;

        for(int i=0;i<4;i++){
            int a = startI+dir[i][0];
            int b = startJ+dir[i][1];

            if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==1 && !visited[a][b]){
                dfsUtil(a,b,m,n,grid,visited);
            }
        }
    }

    void dfs(int m,int n,vector<vector<int> > &grid, vector<vector<bool> > &visited) {

        // first row
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfsUtil(0,j,m,n,grid,visited);
            }
        }

        // last row
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                dfsUtil(m-1,j,m,n,grid,visited);
            }
        }

        // first column
        for(int i=0;i<m;i++){
           if(grid[i][0]==1 && !visited[i][0]){
                dfsUtil(i,0,m,n,grid,visited);
            }
        }

        // last column
        for(int i=0;i<m;i++){
           if(grid[i][n-1]==1 && !visited[i][n-1]){
                dfsUtil(i,n-1,m,n,grid,visited);
            }
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool> (n));

        // start dfs from all boundary 1s
        dfs(m,n,grid,visited);

        int count=0;

        // return count of unvisited 1s
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};