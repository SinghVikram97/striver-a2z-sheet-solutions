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