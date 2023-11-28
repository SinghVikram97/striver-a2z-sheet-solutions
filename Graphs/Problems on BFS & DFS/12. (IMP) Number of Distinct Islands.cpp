// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Keep b/Applications/Visual Studio Code.app/Contents/Resources/app/out/vs/code/electron-sandbox/workbench/workbench.htmlase and substract others from it

// ** need to use set as for unordered_set we need to provide our own hash function with complex types

class Solution {
  public:

    vector<vector<int> > dir = {{0,-1},{-1,0},{0,1},{1,0}};

    void dfs(int startI,int startJ, vector<vector<int> > &grid, 
            vector<vector<bool> > &visited, vector<pair<int,int> > &path, 
            int baseI,int baseJ) {

      int m = grid.size();
      int n = grid[0].size();

      visited[startI][startJ]=true;
      path.push_back({startI-baseI,startJ-baseJ});

      for(int i=0;i<4;i++){
          int newI = startI + dir[i][0];
          int newJ = startJ + dir[i][1];

          if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1 && !visited[newI][newJ]){
            dfs(newI,newJ,grid,visited,path,baseI,baseJ);
          }
      }
    }


    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool> > visited(m,vector<bool>(n));
        set<vector<pair<int,int> > > ms; 
        
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !visited[i][j]){
               vector<pair<int,int> > path;
               dfs(i,j,grid,visited,path,i,j);
               ms.insert(path);
            }
          }
        }

        return ms.size();

    }
};