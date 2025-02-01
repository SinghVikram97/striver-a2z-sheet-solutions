// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

// Here each step has weight 1 so we can use normal bfs to find shortest path
#define m 100000
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> mq;
        
        int n=arr.size();
        
        mq.push(start);
        
        int steps=0;
        
        vector<bool> visited(m, 0); // stores visited start since no use of calculating for same start
        // start rotates from 0 to m-1 as we do mod
        visited[start]=true;
        
        while(!mq.empty()){
            int size=mq.size();
            
            for(int i=0;i<size;i++){
                int curStart=mq.front();
                mq.pop();
                
                if(curStart==end){
                    return steps;
                }
                
                for(int j=0;j<arr.size();j++){
                    // generate new possible starts
                    int newStart=((curStart%m)*(arr[j]%m))%m;
                    if(!visited[newStart]){
                        mq.push(newStart);
                        visited[newStart]=true;
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};
