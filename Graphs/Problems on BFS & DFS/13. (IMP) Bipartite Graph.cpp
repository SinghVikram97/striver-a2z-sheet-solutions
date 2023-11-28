// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:

    bool bfs(int startV, vector<bool> &visited, vector<vector<int> > &graph, unordered_set<int> &setA, unordered_set<int> &setB){
        queue<int> mq;

        mq.push(startV);
        visited[startV]=true;
        setA.insert(startV); 

        while(!mq.empty()){

            int front = mq.front();
            mq.pop();

            bool inSetA=false;

            // Find which set front belongs to
            if(setA.find(front)!=setA.end()) {
                inSetA=true; 
            }

            for(int i=0;i<graph[front].size();i++){
                int child=graph[front][i];

                if(!visited[child]){
                    // put in opposite set
                    if(inSetA){
                        setB.insert(child);
                    }else{
                        setA.insert(child);
                    }
                    visited[child]=true;
                    mq.push(child);
                }
                else{
                    // if visited check if it exists in the same set or not
                    bool childInSetA = false;
                    if(setA.find(child)!=setA.end()){
                        childInSetA=true;
                    }
                    if(inSetA && childInSetA){
                        return false;
                    }
                    if(!inSetA && !childInSetA){
                        // both in B
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int numVertices=graph.size();
        vector<bool> visited(numVertices);
        unordered_set<int> setA;
        unordered_set<int> setB;

        for(int i=0;i<numVertices;i++){
            if(!visited[i]){
                if(!bfs(i, visited, graph, setA, setB)){
                    return false;
                }
            }
        }
        return true;
    }
};