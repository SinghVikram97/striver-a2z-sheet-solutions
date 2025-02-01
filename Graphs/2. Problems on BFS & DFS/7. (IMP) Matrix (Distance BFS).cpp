// https://leetcode.com/problems/01-matrix/description/

// BFS can be used to find smallest distance in undirected graph

// To make distance 0 for every cell having 0 start bfs from every 0
// ie. push those cells into the queue

class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int> > mq;

        vector<vector<bool> > visited(m,vector<bool>(n));

        // push all zeroes to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    mq.push({i,j});
                    visited[i][j]=true;
                }
            }
        }

        int dist = 1; 
        // Start BFS from all zeroes as source
        while(!mq.empty()) {
            int size = mq.size();

            // each level will have dist = dist + 1
            for(int i=0;i<size;i++){
                pair<int,int> front = mq.front();
                mq.pop();

                int x = front.first;
                int y = front.second;

                for(int j=0;j<4;j++){
                    int a = x+dir[j][0];
                    int b = y+dir[j][1];

                    if(a>=0 && a<m && b>=0 && b<n && !visited[a][b]){
                        visited[a][b]=true;
                        mat[a][b]=dist;
                        mq.push({a,b});
                    }
                }

            }
            dist++;
        }

        return mat;
    }
};

// 2nd time
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int n=mat.size();
        int m=mat[0].size();

        // -1 means distance not calculated yet
        vector<vector<int> > dist(n, vector<int>(m,-1));
        queue<pair<int,int> > mq;

        // push all zereos and their distance will be 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    mq.push({i,j});
                }
            }
        }

        int currentDist=0;
        while(!mq.empty()){
            int size=mq.size();

            // level wise
            currentDist++;
            for(int i=0;i<size;i++){
                pair<int,int> node = mq.front();
                mq.pop();

                // check if adjacent cell is 1 update its distance
                for(int j=0;j<dir.size();j++){
                    int newRow=node.first+dir[j][0];
                    int newCol=node.second+dir[j][1];

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && dist[newRow][newCol]==-1){
                        dist[newRow][newCol]=currentDist;
                        mq.push({newRow, newCol});
                    }
                }

            }
        }

        return dist;
    }
};