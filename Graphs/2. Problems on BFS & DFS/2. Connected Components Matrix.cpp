// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
class Solution {
  public:
    void bfs(int startVertex, int V, vector<bool> &visited, vector<vector<int> > &adj){

        queue<int> mq;
        mq.push(startVertex);
        visited[startVertex]=true;

        while(!mq.empty()){
            int front = mq.front();
            mq.pop();

            for(int i=0;i<adj[front].size();i++){
                if(adj[front][i] && !visited[i]){
                    mq.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V);
        int ans=0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,V,visited,adj);
                ans++;
            }
        }

        return ans;
    }
};