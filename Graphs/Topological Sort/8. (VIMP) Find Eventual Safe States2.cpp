// https://leetcode.com/problems/find-eventual-safe-states/description/

/*

Initially the terminal nodes are those who have outdegree 0 
but after reversal the terminal nodes becomes those which have indegree 0 
so we can apply Kahn's algo to find all the nodes connected to it
which have linear dependency on the terminal node or is on the path which leads to terminal node 
so if the nodes is a part of a cycle or points to a cycle ,
that path cannot lead to terminal node as each node in that  path will have cyclic dependency

*/


class Solution {
public:

    vector<int> topoSort(vector<vector<int> > &adj, int n) {
        // calculate indegree 
        vector<int> indegree(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                int child = adj[i][j];
                // edge from i -> child
                indegree[child]++;
            }
        }

        // push nodes with indegree 0 into a queue
        vector<int> topoSort; // ans;

        queue<int> mq;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                mq.push(i);
                topoSort.push_back(i);
            }
        }

        while(!mq.empty()){

            int front = mq.front();
            mq.pop();

            // reduce indegree of child by 1 and push into queue if 0
            for(int i=0;i<adj[front].size();i++){
                int child = adj[front][i];
                indegree[child]--;

                if(indegree[child]==0){
                    mq.push(child);
                    topoSort.push_back(child);
                }
            }
        }

        sort(topoSort.begin(), topoSort.end());
        return topoSort;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int> > adjRev(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int child = graph[i][j];
                // edge from i -> child
                adjRev[child].push_back(i);
            }
        }

        return topoSort(adjRev,n);
    }
};