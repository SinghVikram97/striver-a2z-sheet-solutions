// Minimum spanning tree

/*
Definition
A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) 
and N-1 edges and all nodes are reachable from each other.

Among all possible spanning trees of a graph, MST is the one for which sum of all edge weights is minimum

MST is for undirected graph

Prim's and Kruskal's algorithms output a minimum spanning tree for connected and "undirected" graphs. 
If the graph is not connected, we can tweak the algorithms to output minimum spanning forests.

Both work with negative edges and cyclic graphs

*/

// Prim's Algo - Greedy
/*
Start from any node this node will sure be part of MST since everyone is
Now from this node select minimum edge weight now we have 2 nodes (x,y)
Now select edges from x,y with minumum edge weight 
Keep a visited array to not include same node twice

Time complexity -> O(ElogV)
*/

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        

        // minimum priority queue 
        // if you want MST as well push {wt, node, parentNode}
        // note weight here is edgeWeight
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> >> pq;

        // start from any vertex
        pq.push({0, 0});  // 0 based index

        vector<int> visited(V, false);

        int mstwt=0;

        while(!pq.empty()) {
            pair<int,int> topEle=pq.top();
            pq.pop();

            int wt=topEle.first;
            int node=topEle.second;

            // This is important
            if(visited[node]){
                continue; // already in MST
            }

            // IMP: we are marking it as visited only when taking it out from the priority queue
            visited[node]=true;
            mstwt+=wt; // wt from prev node

            // push edges from this node into pq
            for(int i=0;i<adj[node].size();i++){
                int adjNode=adj[node][i][0];
                int adjWt=adj[node][i][1];

                if(!visited[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return mstwt;
    } 
};/