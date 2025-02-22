// https://leetcode.com/problems/course-schedule/

// Just find out if topo sort possible

class Solution {
public:

    vector<int> topoSort(int n, vector<vector<int>>& adjList){
        vector<int> indegree(n);
        vector<int> ans;

        for(int i=0;i<adjList.size();i++){
            for(int j=0;j<adjList[i].size();j++){
                // edge from i -> x
                int child=adjList[i][j];
                indegree[child]++;
            }
        }

        // put all vertices with 0 indegree in queue
        queue<int> mq;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                mq.push(i);
                ans.push_back(i);
            }
        }

        while(!mq.empty()){
            int front=mq.front();
            mq.pop();

            for(int i=0;i<adjList[front].size();i++){
                int child=adjList[front][i];
                indegree[child]--;
                if(indegree[child]==0){
                    mq.push(child);
                    ans.push_back(child);
                }
            }
        }
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > adjList(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
             //  you must taken course b first if you want to take course a
            // b->a
            adjList[b].push_back(a);
        }


        vector<int> topologicalSort = topoSort(numCourses, adjList);
        if(topologicalSort.size()==numCourses){
            return true;
        }else{
            return false;
        }
    }
};

// Using DFS
class Solution {
public:
    // returns true if there is a cycle
    bool dfs(int startVertex, vector<bool> &visited, vector<bool> &pathVisited, unordered_map<int,vector<int> > &adjList){
        visited[startVertex]=true;
        pathVisited[startVertex]=true;

        // visit neighbours
        for(int i=0;i<adjList[startVertex].size();i++){
            int neighbour=adjList[startVertex][i];

            if(!visited[neighbour]){
                if(dfs(neighbour, visited, pathVisited, adjList)){
                    return true;
                }else{
                    continue;
                }
            }else{
                if(pathVisited[neighbour]){
                    return true;
                }else{
                    continue;
                }
            }
        }

        // remove from path visited - backtrack
        pathVisited[startVertex]=false;

        // No cycle
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int> > adjList;

        int n=prerequisites.size();

        for(int i=0;i<n;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adjList[a].push_back(b); // a->b , a depends on b
        }

        vector<bool> visited(numCourses+5);
        vector<bool> pathVisited(numCourses+5);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(i, visited, pathVisited, adjList)){
                return false;
            }
        }
        return true;
    }
};