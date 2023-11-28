// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool dfs(int startVertex, int V, int parent, unordered_map<int,int> &visited, vector<int> adj[]) {
        visited[startVertex]=parent;

        // visit children
        for(int i=0;i<adj[startVertex].size();i++){
            int vertex = adj[startVertex][i];

            if(visited.find(vertex)==visited.end()){
                // visit
                if(dfs(vertex, V, startVertex, visited, adj)){
                    return true;
                }
            }
            else{
                // already visited
                // check if startVertex was pushed by vertex
                // ie. if parent of startVertex -> vertex
                if(visited[startVertex]==vertex){
                    // alright
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,int> visited;

        for(int i=0;i<V;i++){
            if(visited.find(i)==visited.end() && dfs(i, V, i, visited, adj)) {
                return true;
            }
        }

        return false;
    }
};