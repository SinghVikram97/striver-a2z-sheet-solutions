// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

/*
Look at test case graph
ways to reach 6 with minimum distance will ie. 7
will be ways to reach 4 with distance 5 (7-edge weight b/w 4 and 6)
+ ways to reach 3 with distance 4
+ ways to reach 5 with distance 6 (ie. min distance of 5)
+ ways to reach 0 with distance 7

so we store along with distance the ways to reach a given node with minimum distance from src

while doing Dijsktra update ways if we get another path with same minimum distance
but don't push again to priority queue

IMP:
for example if distance to reach node 5 from src = 3
if we see from another node that dist to reach node 5 from src = 3
update ways 
but don't push {3,5} ie. node 5 at distance 3 again no use

*/

// IMP: see word ladder 2 as well, first we find shortest path using bfs, and then all possible paths using dfs
// But here distance not unit distance
#define ll long long int
#define m 1000000007
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll> > > adjList(n);

        for(ll i=0;i<roads.size();i++){
            ll u=roads[i][0];
            ll v=roads[i][1];
            ll time=roads[i][2];

            adjList[u].push_back({v,time});
            adjList[v].push_back({u, time});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1; // ways to start from source = 1

        while(!pq.empty()){
            pair<ll,ll> topEle=pq.top();
            pq.pop();

            ll curNode=topEle.second;
            ll distCurFromSrc=topEle.first;

            for(ll i=0;i<adjList[curNode].size();i++){
                ll neighbour=adjList[curNode][i].first;
                ll distNeighbourFromCur=adjList[curNode][i].second;

                ll distNeighbourFromSrc=distCurFromSrc+distNeighbourFromCur;

                if(distNeighbourFromSrc<dist[neighbour]){
                    ways[neighbour]=ways[curNode]%m;
                    dist[neighbour]=distNeighbourFromSrc;
                    pq.push({distNeighbourFromSrc, neighbour});
                }else if(distNeighbourFromSrc==dist[neighbour]){
                    ways[neighbour]=((ways[neighbour]%m)+(ways[curNode]%m))%m;
                    // don't push again with same distance no use
                }
            }
        }
        
        return ways[n-1]%m;
    }
};