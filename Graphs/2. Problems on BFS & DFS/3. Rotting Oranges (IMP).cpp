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


// 2nd time
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int n=grid.size();
        int m=grid[0].size();

        // push all rotten oranges in queue
        queue<pair<int,int> > mq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    mq.push({i,j});
                }
            }
        }

        int minutes=0;
        while(!mq.empty()){
            int size=mq.size();

            // process all rotten oranges at minute 1
            for(int i=0;i<size;i++){
                pair<int,int> node = mq.front();
                mq.pop();

                // turn fresh oranges to rotten and push them onto queue
                for(int j=0;j<dir.size();j++){
                    int newRow=node.first+dir[j][0];
                    int newCol=node.second+dir[j][1];

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1){
                        grid[newRow][newCol]=2;
                        mq.push({newRow,newCol});
                    }
                }
            }

            minutes++;
        }

         // Check if all rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        if(minutes==0){
            // already rotten all
            return minutes;
        }
        return minutes-1;
    }
};