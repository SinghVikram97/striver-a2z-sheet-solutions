// https://practice.geeksforgeeks.org/problems/topological-sort/1

void dfs(int startVertex, int V, vector<int> adj[], vector<bool> &visited, stack<int> &ms){

    visited[startVertex]=true;

    // visit neighbours 
    for(int i=0;i<adj[startVertex].size();i++){
        int child = adj[startVertex][i];

        if(!visited[child]){
            dfs(child, V, adj, visited, ms);
        }
    }

    // Will come before neighbours/at top in stack so push last
    ms.push(startVertex);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
	vector<bool> visited(V);
    
    stack<int> ms;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, V, adj, visited, stack);
        }
    }

    vector<int> topoSort;
    while(!ms.empty()){
        int top = ms.top();
        ms.pop();
        topoSort.push_back(top);
    }

    return topoSort;
}