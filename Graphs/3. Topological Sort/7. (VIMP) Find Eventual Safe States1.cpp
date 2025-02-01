// https://leetcode.com/problems/find-eventual-safe-states/description/

// Terminal node -> no outgoing edge
// Safe node -> leads to a terminal node

// Terminal node can't be a part of the cycle
// Any node which is part of a cycle can't be a safe node
// Any node which also leads to cycle can't be a safe node and it would reach cycle start again

// ex.   1->2->3 
//        \  /
//         4   4->1 and 3->4
//         |
//         5

// 5 also not a safe node


class Solution {
public:

    // checks for cycle
    bool dfs(int startVertex, vector<vector<int> > &graph, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &checkSafe){
        visited[startVertex]=true;
        pathVisited[startVertex]=true;

        for(int i=0;i<graph[startVertex].size();i++){
            int child = graph[startVertex][i];

            if(!visited[child]){
                if(dfs(child, graph, visited, pathVisited, checkSafe)){
                    checkSafe[startVertex]=false; // part of cycle or cycle starts
                    return true;
                }
            }else{
                if(pathVisited[child]){
                    checkSafe[startVertex]=false;
                    return true;
                }
            }
        }

        // not part of cycle 
        checkSafe[startVertex]=true;
        pathVisited[startVertex]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> visited(n);
        vector<bool> pathVisited(n);
        vector<bool> checkSafe(n); // true means it is safe node

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, graph, visited, pathVisited, checkSafe);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(checkSafe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};