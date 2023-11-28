// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:

    void bfs(int startVertex, vector<bool> &isVisited, vector<vector<int> > &isConnected) {
        queue<int> mq;
        mq.push(startVertex);
        isVisited[startVertex]=true;

        while(!mq.empty()) {
            int front = mq.front();
            mq.pop();

            for(int i=0;i<isConnected[front].size();i++) {
                if(isConnected[front][i] && !isVisited[i]){
                    isVisited[i]=true;
                    mq.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfVertices = isConnected.size();
        vector<bool> isVisited(numOfVertices);

        int ans=0;

        for(int i=0;i<numOfVertices;i++){
            if(!isVisited[i]) {
                bfs(i, isVisited, isConnected);
                ans++;
            }
        }
        return ans;
    }
};