// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
class Solution {
public:
    void dfs(int startVertex, unordered_map<int,vector<int> > &adjList, vector<bool> &visited){
        visited[startVertex]=true;

        for(int i=0;i<adjList[startVertex].size();i++){
            int neighbour=adjList[startVertex][i];

            if(!visited[neighbour]){
                dfs(neighbour, adjList, visited);
            }
        }

        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        // stoneNumber, list of stoneNumbers it is connected to
        unordered_map<int, vector<int> > adjList;

        int numStones=stones.size();
        
        for(int i=0;i<numStones;i++){
            int x1=stones[i][0];
            int y1=stones[i][1];
            
            // i is currentStone
            for(int j=0;j<i;j++){
                int x2 = stones[j][0];
                int y2 = stones[j][1];

                if(x1==x2 || y1==y2){
                    // insert into adjList stone numbers
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }

        }

        // for(int i=0;i<numStones;i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<adjList[i].size();j++){
        //         cout<<adjList[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> visited(numStones,false);

        int components=0;

        for(int i=0;i<numStones;i++){
            if(!visited[i]){
                dfs(i, adjList, visited);
                components++;
            }
        }

        return numStones-components;
    }
};