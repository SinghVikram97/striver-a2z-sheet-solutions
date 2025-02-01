// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Can't use the same algo as undirected that if already visited and not parent then cycle

// For example   0  --- 1  Cycle 
//                \    /
//                 \ /
//                  2

// For example   0  ---> 1  No cycle 
//                \    /
//                 \/ \/
//                   2

// 5 --> 3 <--- 1 and 5 --> 1 , no cycle, although 3 already visited

// Key idea: In a given recursion stack there shouldn't be a vertex which is already visited in same dfs stack


// we keep 2 visited arrays
// one overall isVisited ie. we have already tried dfs starting from this vertex so need to do again
// dfsVisited ie. all nodes that have been visited in current dfs (in same direction)
// after dfs gets finished after a node we mark it unvisited again 

// if same node visited in same dfs then cycle
// ie. if dfsVisited is true

bool dfs(int startVertex, int V, vector<int> adj[],  vector<bool> &isVisited, vector<bool> &isDfsVisited) {
    isVisited[startVertex]=true;
    isDfsVisited[startVertex]=true;

    for(int i=0;i<adj[startVertex].size();i++){
        int child=adj[startVertex][i];

        if(!isVisited[child]){
            if(dfs(child, V, adj, isVisited, isDfsVisited)){
                return true;
            }
        }else{
            if(isDfsVisited[child]){
                return true;
            }
        }
    }

    isDfsVisited[startVertex]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    
    vector<bool> isVisited(V);
    vector<bool> isDfsVisited(V);

    for(int i=0;i<V;i++){
        if(!isVisited[i]){
            if(dfs(i, V, adj, isVisited, isDfsVisited)){
                return true;
            }
        }
    }
    return false;
}


