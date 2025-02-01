// https://leetcode.com/problems/path-with-minimum-effort/description/

// Using Dijkstra , can use BFS as well but not optimial similar to Q2 in this folder

// Note here we don't have to find the distance
// Instead we want the max diff b/w 2 nodes in the path

// So instead of
/*
int distNeighbourFromSource = distTopFromSource + abs(heights[newRow][newCol]-heights[rowNo][colNo]))

We do
int distNeighbourFromSource = max(distTopFromSource , abs(heights[newRow][newCol]-heights[rowNo][colNo]));
*/

class Solution {
public:
    vector<vector<int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    int solve(vector<vector<int> > &heights){
        int m=heights.size();
        int n=heights[0].size();
        
        // dist, (i,j)
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >> > pq;
        pq.push({0,{0,0}});

        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;

        while(!pq.empty()){
            pair<int,pair<int,int> > topEle=pq.top();
            pq.pop();

            int rowNo = topEle.second.first;
            int colNo = topEle.second.second;
            int distTopFromSource=topEle.first;

            // traverse adjacency list
            for(int i=0;i<dir.size();i++){
                int newRow=rowNo+dir[i][0];
                int newCol=colNo+dir[i][1];

                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                    int distNeighbourFromSource = max(distTopFromSource , abs(heights[newRow][newCol]-heights[rowNo][colNo]));

                    if(distNeighbourFromSource < dist[newRow][newCol]){
                        dist[newRow][newCol]=distNeighbourFromSource;

                        pq.push({distNeighbourFromSource, {newRow, newCol}});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        return dist[m-1][n-1];

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return solve(heights);
    }
};