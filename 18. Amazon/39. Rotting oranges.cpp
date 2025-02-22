// https://leetcode.com/problems/rotting-oranges/description/
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