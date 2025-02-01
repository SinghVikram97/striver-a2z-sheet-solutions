// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

// Min number of edges to connect N nodes = N-1

// Number of edges to connect D disconnected components = D-1

/*
So we need D-1 extra edges to connected these D disconnected components which we have to removed from existing graph
So we need D-1 extra edges, extra in terms that even if we remove an edge the component remains connected

So for an edge u,v if ultimate parent of u and v already same then this edge we consider extra

Now for number of components we can go through parent array and check if for a node ultimate parent is root itself it is head node
Number of such nodes = number of these components


Number of times we need to do this = D-1 (if we have atleast that many extra edges)

Time complexity -> O(E*4α)+O(N*4α), 4α is constant
Space -> O(2N)
*/
class DisjointSet{
    vector<int> rank, parent, size;

    public:
        DisjointSet(int n){
            // both 1 based and 0 based indexing

            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }


        int findUltimateParent(int node){
            if(parent[node]==node){
                // root
                return node;
            }else{
                // do path compression
                // find parent of its parent till we reach root
                return parent[node]=findUltimateParent(parent[node]);
            }
        }

        void unionByRank(int u, int v){
            int ultimateParentU = findUltimateParent(u);
            int ultimateParentV = findUltimateParent(v);

            if(ultimateParentU==ultimateParentV){
                // In same
                return;
            }

            // Only change rank if ranks equal
            // Otherwise we are attaching smaller to bigger so no effect to bigger
            if(rank[ultimateParentU]>rank[ultimateParentV]){
                // attach V to U so ultimateParent of V attaches to U
                parent[ultimateParentV]=ultimateParentU;
            }else if(rank[ultimateParentU]<rank[ultimateParentV]){
                // attach U to V
                parent[ultimateParentU]=ultimateParentV;
            }else{
                // ranks equal attach anyone to anyone
                // attach U to v
                parent[ultimateParentU]=ultimateParentV;
                // change rank
                rank[ultimateParentV]++;
            }
        }

        void unionBySize(int u, int v){
            int ultimateParentU = findUltimateParent(u);
            int ultimateParentV = findUltimateParent(v);

            if(ultimateParentU==ultimateParentV){
                // In same
                return;
            }

            if(size[ultimateParentU]>size[ultimateParentV]){
                // attach V to U
                parent[ultimateParentV]=ultimateParentU;
                size[ultimateParentU]+=size[ultimateParentV];
            }else{
                // no equal case separately we can do in single else condition
                // atach U to V

                parent[ultimateParentU]=ultimateParentV;
                size[ultimateParentV]+=size[ultimateParentU];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        DisjointSet ds(n);

        int extraEdges=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            if(ds.findUltimateParent(u)==ds.findUltimateParent(v)){
                extraEdges++;
            }else{
                ds.unionByRank(u,v);
            }
        }

        // Find number of components
        int numComponents=0;

        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i)==i){
                numComponents++;
            }
        }

        int numTimes=numComponents-1;

        if(extraEdges>=numTimes){
            return numTimes;
        }else{
            return -1;
        }
    }
};

// We can also do DFS and find number of connected components and return D-1
// Because if numEdges >= n-1 then it means we have extra edges
/*
we are checking if(connections.size() < n-1) here n is total number of computers not the number of computers in one component. 
So, if total number of computers are n then we would need a total of n-1 edges to make all the computers connected.
So, in total irrespective of how many components we have and where are all the edges are available 
if the total number of edges in whole graph is atleast n-1 then they can be used to connect the whole graph

*/
class Solution {
public:
    void dfs(int startVertex, unordered_map<int,vector<int> > &adjList, vector<bool> &visited){
        visited[startVertex]=true;

        for(int i=0;i<adjList[startVertex].size();i++){
            int neighbour=adjList[startVertex][i];

            if(!visited[neighbour]){
                dfs(neighbour, adjList, visited);
            }
        }

        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numEdges=connections.size();

        if(numEdges<n-1){
            return -1;
        }

        unordered_map<int,vector<int> > adjList;

        for(int i=0;i<numEdges;i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n,false);

        int components=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, adjList, visited);
                components++;
            }
        }

        return components-1;
    }
};