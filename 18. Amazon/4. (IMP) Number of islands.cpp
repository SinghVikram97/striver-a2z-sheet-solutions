// https://leetcode.com/problems/number-of-islands/description
class Solution {
public:
    vector<pair<int,int> > dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool> > &visited){
        int m=grid.size();
        int n=grid[0].size();

        visited[i][j]=true;

        for(int k=0;k<dir.size();k++){
            int x=i+dir[k].first;
            int y=j+dir[k].second;

            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1' && !visited[x][y]){
                dfs(grid,x,y,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool> > visited(m,vector<bool>(n)); 

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    count++;
                }
            }
        }

        return count;

    }
};