// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Can use BFS 

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){

        // build adjList
        vector<vector<int> > adjList(N);


        // N nodes, M edges
        for(int i=0;i<M;i++){
           // edge b/w edges[i][0] and edges[i][1]
           int a = edges[i][0];
           int b = edges[i][1];

           adjList[a].push_back(b);
           adjList[b].push_back(a);
        }
    

        vector<int> dist(N,-1);
        vector<bool> visited(N);

        queue<int> mq;
        mq.push(src);
        visited[src]=true;
        dist[src]=0;

        int curDist=1;
        while(!mq.empty()){

            int size  = mq.size();

            for(int i=0;i<size;i++){
                // All same level
                int front = mq.front();
                mq.pop();

                for(int j=0;j<adjList[front].size();j++){
                    int neighbour = adjList[front][j];
                    if(!visited[neighbour]){
                        mq.push(neighbour);
                        visited[neighbour]=true;
                        dist[neighbour]=curDist;
                    }
                }
            }

            curDist++;

        }

        return dist;

    }
};
