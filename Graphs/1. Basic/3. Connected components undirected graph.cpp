// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
class Solution {
  public:
    vector<int> bfs(int startVertex, vector<vector<int> > &adjList, vector<bool> &visited){
        queue<int> mq;
        visited[startVertex]=true;
        mq.push(startVertex);
        vector<int> ans;
        
        while(!mq.empty()){
            int node=mq.front();
            mq.pop();
            
            ans.push_back(node);
            
            for(int i=0;i<adjList[node].size();i++){
                if(!visited[adjList[node][i]]){
                    visited[adjList[node][i]]=true;
                    mq.push(adjList[node][i]);
                }
            }
        }
        
        return ans;
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
       vector<vector<int> > adjList(v);
       
       for(int i=0;i<edges.size();i++){
           int a=edges[i][0];
           int b=edges[i][1];
           
           adjList[a].push_back(b);
           adjList[b].push_back(a);
       }
       
       vector<bool> visited(v, false);
       
       vector<vector<int> > finalAns;
       
       for(int i=0;i<v;i++){
           if(!visited[i]){
               vector<int> bfsAns=bfs(i, adjList, visited);
               // For gfg -> sort(bfsAns.begin(), bfsAns.end());
               finalAns.push_back(bfsAns);
           }
       }
       
       return finalAns;
    }
};