// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


// Time Complexity: O(V+E) adjacency list
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int start, int v, vector<int> adj[], vector<bool> &visited, vector<int> &ans) {
        queue<int> mq;
        mq.push(start);
        visited[start]=true;

        while(!mq.empty()) {
            int front = mq.front();
            mq.pop();
            ans.push_back(front);

            for(int i=0;i<adj[front].size();i++) {
                if(!visited[adj[front][i]]){
                    mq.push(adj[front][i]);
                    visited[adj[front][i]]=true;
                }
            }
        }
        return;
    }

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

       vector<bool> visited(V);

       vector<int> ans;

    //    for(int i=0;i<V;i++){
    //       if(!visited[i]) {
    //          bfs(i, V, adj, visited, ans);
    //       }
    //    }

       // only from 0
       bfs(0, V, adj, visited, ans);
       return ans;
    }
};