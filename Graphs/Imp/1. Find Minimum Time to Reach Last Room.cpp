// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
#define ll long long int
class Solution {
public:
    vector<vector<int > > dir={{-1,0},{0,1},{1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int> > dist(n, vector<int> (m,INT_MAX-5));
        
        priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >> > pq;
        pq.push({0, {0,0}});
        dist[0][0]=0;
        
        while(!pq.empty()){
            pair<int, pair<int,int> > curr=pq.top();
            pq.pop();
            
            int time=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            
            for(int k=0;k<dir.size();k++){
                int newRow=i+dir[k][0];
                int newCol=j+dir[k][1];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                    int newTime=max(time, moveTime[newRow][newCol])+1;
                    
                    if(newTime<dist[newRow][newCol]){
                        dist[newRow][newCol]=newTime;
                        pq.push({newTime, {newRow, newCol}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};