// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


// O(V3) using Floyd Warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dist(n, vector<int>(n, INT_MAX-10));

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];  

            dist[u][v]=w;
            dist[v][u]=w;
        }

        // distance from node to itself is 0
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX-10 && dist[k][j]!=INT_MAX-10){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        // replace unreachable cities distance by -1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==INT_MAX-10){
                    dist[i][j]=-1;
                }
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }

        int cityNumber = -1;
        int minCount=INT_MAX;

        for(int i=0;i<n;i++){
            int count=0;

            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    count++;
                }
            }

            if(count<=minCount){
                cityNumber=max(cityNumber, i);
                minCount=count;
            }
        }

        return cityNumber;
    }
};

// Since distances are positive we can also use Dijkstra by doing Dijsktra by considering every vertex as the source node
/*
n vertices m edges
For one source, Dijkstra's algorithm using a priority queue runs in O(ElogV). 
With the maximum number of edges m, this becomes O(V⋅(V−1)/2⋅logV)=O(V2logn). 
Running Dijkstra's algorithm for each city (source), the overall time complexity is O(V⋅V2logn)=O(V3logn).
*/

// Bellman Ford
/*
For one source bellman ford algorithm runs in O(VE)
For max number of edges it is O(V. V(V-1)/2) = O(V3)
For every source it becomes O(V4)
*/

// Floyd Warshall
// The Floyd-Warshall algorithm directly computes the shortest paths between all pairs of cities in O(n3)
// regardless of the number of edges. This comes from the three nested loops, each iterating n times.