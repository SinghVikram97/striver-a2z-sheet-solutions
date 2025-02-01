// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Using BFS

class Solution {
  public:
     bool bfs(int startVertex, unordered_map<int,int> &visited, vector<int> adj[]) {
        queue<int> mq;
        mq.push(startVertex);
        visited[startVertex]=startVertex; // start vertex will have itself as parent

        while(!mq.empty()) {
            int front = mq.front();
            mq.pop();

            for(int i=0;i<adj[front].size();i++){
                int vertex = adj[front][i];
                if(visited.find(vertex)==visited.end()){
                    // not visited
                    mq.push(vertex);
                    visited[vertex]=front;
                }else{
                    // vertex already visited
                    // check if parent pushed this particular vertex 
                    if(vertex==visited[front]){
                        // it means vertex parent of current vertex
                        // ie. vertex pushed current vertex (front)
                    }
                    else{
                        return true; // cycle
                    }
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,int> visited; // absence-> not visited, presence-> parent

        for(int i=0;i<V;i++){
            if(visited.find(i)==visited.end() && bfs(i,visited,adj)) {
                return true;
            }
        }

        return false;
    }
};