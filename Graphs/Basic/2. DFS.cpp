// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Iterative
// Time Complexity: O(V+E) adjacency list

class Solution {
  public:

    int dfs(int startVertex, int V, vector<int> adj[], vector<bool> &visited, vector<int> &ans){

        stack<int> ms;
        ms.push(startVertex);
        visited[startVertex]=true;

        while(!ms.empty()){
            int top = ms.top();
            ms.pop();
            ans.push(top);

            for(int i=0;i<adj[top].size();i++){
                if(!visited[adj[top][i]]){
                    ms.push(adj[top][i]);
                    visited[adj[top][i]]=true;
                }
            }
        }
    }


    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(0, V, adj, visited, ans);
            }
        }
        return ans;
    }
};


// Recursive
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
   void dfsUtil(int V, int startVertex, vector<int> adj[], vector<int> &visited,vector<int> &ans){
    // mark visited
    visited[startVertex]=true;
    ans.push_back(startVertex);

    // Traverse adjList
    for(int i=0;i<adj[startVertex].size();i++){
        if(!visited[adj[startVertex][i]]){
            dfsUtil(V,adj[startVertex][i],adj,visited,ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
   vector<int> visited(V);
   vector<int> ans;

   dfsUtil(V,0,adj,visited,ans);

   return ans;
}
};