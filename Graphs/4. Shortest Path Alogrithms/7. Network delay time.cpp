// https://leetcode.com/problems/network-delay-time/description/

// Normal Dijsktra
// Minimum time to reach all nodes would be the max distance of any node from src

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > > adjList(n+1);

        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int dist=times[i][2];

            adjList[a].push_back({b,dist});
        }

        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

        vector<int> dist(n+1, INT_MAX);

        dist[k]=0;
        pq.push({0,k}); // dist, node

        while(!pq.empty()){
            pair<int,int> topEle=pq.top();
            pq.pop();

            int distCurNodeFromSrc=topEle.first;
            int curNode=topEle.second;

            for(int i=0;i<adjList[curNode].size();i++){
                int neighbour=adjList[curNode][i].first;
                int distNeighbourFromCurNode=adjList[curNode][i].second;

                int distNeighbourFromSrc = distCurNodeFromSrc + distNeighbourFromCurNode;

                if(distNeighbourFromSrc<dist[neighbour]){
                    dist[neighbour]=distNeighbourFromSrc;
                    pq.push({distNeighbourFromSrc, neighbour});
                }
            }
        }
        
        int maxTime=INT_MIN;

        for(int i=1;i<dist.size();i++){
            maxTime=max(maxTime, dist[i]);
        }

        if(maxTime==INT_MAX){
            return -1;
        }

        return maxTime;
    }
};