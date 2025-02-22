// https://leetcode.com/problems/course-schedule-ii/description/
// https://leetcode.com/problems/course-schedule-ii/description/

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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
            return topologicalSort;
        }else{
            return {};
        }
    }
};