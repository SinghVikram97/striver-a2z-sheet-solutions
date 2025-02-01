// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Undirected graph shortest path = BFS
// Directed graph shortest path with non negative edges = Dijkstra

class Solution {
public:
    vector<vector<int> > dir ={{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1},{0,1},{1,1}};
    
    bool possible(int i, int j, vector<vector<int> > &grid){
        int m=grid.size();
        int n=grid[0].size();

        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==0){
            return true;
        }else{
            return false;
        }
    }
    int bfs(int i, int j, vector<vector<int> > &grid){
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==1){
            return -1; // not possible
        }

        queue<pair<int,int> > mq;
        vector<vector<bool> > visited(m, vector<bool>(n));

        mq.push({0,0});
        visited[0][0]=true;

        int curDist=1;

        while(!mq.empty()){
            int size=mq.size();

            for(int i=0;i<size;i++){
                pair<int,int> curIndex=mq.front();
                mq.pop();

                int rowNo=curIndex.first;
                int colNo=curIndex.second;

                if(rowNo==m-1 && colNo==n-1){
                    return curDist;
                }

                for(int j=0;j<dir.size();j++){
                    int newRow=rowNo+dir[j][0];
                    int newCol=colNo+dir[j][1];

                    if(possible(newRow, newCol, grid) && !visited[newRow][newCol]){
                        mq.push({newRow, newCol});
                        visited[newRow][newCol]=true;
                    }

                }

            }

            curDist++;
        }

        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(0,0,grid);
    }
};