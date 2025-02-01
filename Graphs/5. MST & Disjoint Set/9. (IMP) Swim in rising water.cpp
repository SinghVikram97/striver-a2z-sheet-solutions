// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution {
public:
    vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int> > dist(m, vector<int>(n,INT_MAX));

        dist[0][0]=0;
        
        priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
        

        // time, node
        // IMP push start time not 0
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            pair<int,pair<int,int> > topEle=pq.top();
            pq.pop();

            int currentTime=topEle.first;
            int x=topEle.second.first;
            int y=topEle.second.second;

            for(int k=0;k<4;k++){
                int newI = x + dir[k][0];
                int newJ = y + dir[k][1];
 
                if(newI>=0 && newI<m && newJ>=0 && newJ<n){
                    int newTime=grid[newI][newJ];

                    if(currentTime<newTime){
                        int timeNeighbourFromSrc = currentTime + (newTime-currentTime);

                        if(timeNeighbourFromSrc<dist[newI][newJ]){
                            dist[newI][newJ]=timeNeighbourFromSrc;
                            pq.push({timeNeighbourFromSrc, {newI,newJ}});
                        }
                        
                    }else{
                        // can move freely without any additional time taken
                        int timeNeighbourFromSrc = currentTime + 0;

                        if(timeNeighbourFromSrc<dist[newI][newJ]){
                            dist[newI][newJ]=timeNeighbourFromSrc;
                            pq.push({timeNeighbourFromSrc, {newI,newJ}});
                        }
                    }


                }
            }
        }

        return dist[m-1][n-1];

    }
};