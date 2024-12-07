// https://www.geeksforgeeks.org/problems/shortest-job-first/1
class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        
        long long int time=0;
        
        long long int waitTime=0;
        
        for(int i=0;i<bt.size();i++){
            // waited till time = time since it became available at time=0
            waitTime+=time;
            
            // execute for some time
            time=time+bt[i];
        }
        
        double avgWaitTime=((double) waitTime)/(bt.size());
        
        return floor(avgWaitTime);
    }
};