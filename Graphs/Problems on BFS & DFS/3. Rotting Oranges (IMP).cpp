// https://leetcode.com/problems/rotting-oranges/

// [x,y] -> ([x,y-1],[x,y+1],[x-1,y],[x+1,y]) -> ([0,-1],[0,1],[-1,0],[1,0])

class Solution {
public:
    vector<vector<int> > direction = {{0,-1},{0,1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // push all rotten oranges into queue (visited indicated by the fact that they are rotten)
        queue<pair<int,int> > mq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    mq.push({i,j});
                }
            }
        }

        // Do bfs, take out all the nodes at the same level in the same iteration
        int mins=0;
        while(!mq.empty()){
            int size=mq.size();

            for(int i=0;i<size;i++){
                pair<int,int> front=mq.front();
                mq.pop();

                int x=front.first;
                int y=front.second;

                for(int i=0;i<4;i++){
                    int a=x+direction[i][0];
                    int b=y+direction[i][1];

                    // Check if not out of bounds and not rotten/empty ie.1
                    // If not rotten -> make it rotten and push into queue
                    // So for the next minute they will spoil their neighbours

                    if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==1){
                        grid[a][b]=2;
                        mq.push({a,b});
                    }
                }
            }

            mins++;
        }
        // Check if all rotten
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(mins==0){
            return 0; // already rotten 
        }
        // substract 1 because at last all will be rotten (nothing to push to queue)
        return mins-1;
    }
};