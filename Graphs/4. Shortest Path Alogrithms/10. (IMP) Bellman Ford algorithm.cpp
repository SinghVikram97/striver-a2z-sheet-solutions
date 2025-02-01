// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0
// READ: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/
/*
Bellman-Ford algorithm is a single-source shortest path algorithm, 
so when you have negative edge weight then it can detect negative cycles in a graph.

The only difference between the two is that Bellman-Ford is also capable of handling negative weights 
whereas Dijkstra Algorithm can only handle positives.

Dijkstra is however generally considered better in the absence of negative weight edges, 
as a typical binary heap priority queue implementation has O((|E|+|V|)log|V|) time complexity 
[A Fibonacci heap priority queue gives O(|V|log|V| + |E|)], 

while the Bellman-Ford algorithm has O(|V||E|) complexity

Where Dijkstra's algorithm failed:

If the graph contains negative edges.
If the graph has a negative cycle 
(In this case Dijkstra's algorithm fails to minimize the distance, keeps on running, and goes into an infinite loop. 
As a result it gives TLE error).
Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative. 


Bellman-Ford's algorithm successfully solves these problems. 
It works fine with negative edges as well as it is able to detect if the graph contains a negative cycle. 
But this algorithm is only applicable for directed graphs. 
In order to apply this algorithm to an undirected graph, 
we just need to convert the undirected edges into directed edges like the following:
*/


/*
Key concepts:
1. Relaxation: 

relaxing edge {u,v,w} means
if dist[u]+w<dist[v]:
    dist[v]=dist[u]+w 

where dist is distance from source


2. Relax all edges -> 1 iteration
Relax all edges N-1 times where N = number of nodes ( for intution watch strivers video )
Summary: Since in a graph of N nodes, in worst case, you will take N-1 edges to reach from first to the last
thereby we iterate for N-1 iterations in which all distances will be calculated
Try drawing a graph which takes more than N-1 edges for any path, it is not possible

3. How to detect negative cycles
Since by above after relaxing for N-1 iterations we will have the shortest path, so incase in Nth iteration
We find that we are able to relax an edge and distance is reduced, we would know that we have a negative cycle
*/
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 100000000);
        dist[S]=0;

        // relax edges V-1 times but to check negative cycle run it for V times
        for(int i=1;i<=V;i++){
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                
                // Additional check for checking if vertex has been reached yet or not 
                // IMP check
                if(dist[u]!=100000000 && dist[u]+w<dist[v]){
                    if(i!=V){
                        dist[v]=w+dist[u];
                    }else{
                        return {-1};
                    }
                }

            }
        }

        return dist;
    }
};
