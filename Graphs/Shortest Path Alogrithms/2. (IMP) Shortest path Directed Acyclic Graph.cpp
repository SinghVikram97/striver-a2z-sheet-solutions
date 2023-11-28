// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// Can solve by BFS without visited array
// Some nodes will be pushed twice into the queue, not optimal

// in above example node 2 will be pushed twice
// once with dist 5 and once with dist 3
//**** if we get dist less than what is stored currently then only push again (this stops infinite loop)
// so it can recalulate its neighbours again

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){

        // adjList-> {node,dist} 
        // 0 -> { {1,2},{4,1} }

        vector<vector<pair<int,int> > > adjList(N);

        for(int i=0;i<M;i++){
            // given in format {{0,1,2},...}
            int a = edges[i][0];
            int b = edges[i][1];
            int dist = edges[i][2];

            adjList[a].push_back({b,dist});
        }

        // INT_MAX means not yet calculated
        vector<int> dist(N,INT_MAX);

        int src=0;
        queue<int> mq;
        mq.push(src);
        dist[src]=0;

        while(!mq.empty()) {

            int front = mq.front();
            mq.pop();

            for(int i=0;i<adjList[front].size();i++) {
                pair<int,int> connect=adjList[front][i];

                int node = connect.first;
                int distFromCurNode = connect.second;

                int distFromSrc = dist[front] + distFromCurNode;

                if(distFromSrc < dist[node]) {
                    // Only push again if we get a smaller dist
                    // INT_MAX to take care of this condition
                    dist[node] = distFromSrc;
                    mq.push(node);
                }
            }


        }
        
        // Check if can't visit a node replace INT_MAX with -1
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }

        return dist;

    }
};


// Efficient Approach
// Instead of pushing twice if we do toposort so that first we calculate dist of pre-requisite node
// first then no redundancy 

// Toposort - O(V+E)
class Solution {
  public:

    vector<int> topo(vector<vector<pair<int,int> > > &adjList, int numVerticies, int numEdges) {
        
        // calculate indegree
        vector<int> indegree(numVerticies);

        for(int i=0;i<numVerticies;i++){
            for(int j=0;j<adjList[i].size();j++){
                // edge from i -> pair.first
                pair<int,int> neighbour = adjList[i][j];
                indegree[neighbour.first]++;
            }
        }

        vector<int> topoSort;
        queue<int> mq;

        // push nodes with indegree 0 into the queue
        for(int i=0;i<numVerticies;i++){
            if(indegree[i]==0){
                mq.push(i);
                topoSort.push_back(i);
            }
        }

        while(!mq.empty()) {
            int front = mq.front();
            mq.pop();


            for(int i=0;i<adjList[front].size();i++){
               pair<int,int> neighbour = adjList[front][i];
               int node = neighbour.first;
               indegree[node]--;

               if(indegree[node]==0){
                  mq.push(node);
                  topoSort.push_back(node);
               }
            }
        }

        return topoSort;
    }

    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // adjList-> {node,dist} 
        // 0 -> { {1,2},{4,1} }

        vector<vector<pair<int,int> > > adjList(N);

        for(int i=0;i<M;i++){
            // given in format {{0,1,2},...}
            int a = edges[i][0];
            int b = edges[i][1];
            int dist = edges[i][2];

            adjList[a].push_back({b,dist});
        }


        vector<int> topoSort = topo(adjList,N,M);

        vector<int> dist(N,INT_MAX);

        int src=0;

        dist[src]=0;

        // All nodes before src node in topo_sort will be unreachble from src node
        // So their distance will remain INT_MAX

        for(int i=0;i<topoSort.size();i++){
            int curNode = topoSort[i];

            // relax edges of current node
            for(int j=0;j<adjList[curNode].size();j++){
                pair<int,int> neighbour = adjList[curNode][j];

                int node = neighbour.first;
                int distFromCurNode = neighbour.second;
                
                // check if curNode reachable from src
                // to avoid overflow
                // ie. INT_MAX+9 < INT_MAX
                if(dist[curNode]==INT_MAX){
                    continue;
                }

                else if(dist[curNode]+distFromCurNode<dist[node]){
                    dist[node]=dist[curNode]+distFromCurNode;
                }
            }
        }

         // Check if can't visit a node replace INT_MAX with -1
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }

        return dist;
    }
};