// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Execute job with max profit at last possible time
class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n) {
        unordered_set<int> time;
        
        vector<pair<int,int> > v;
        
        for(int i=0;i<n;i++){
            v.push_back({jobs[i].profit, jobs[i].deadline});
        }
        
        sort(v.begin(), v.end(), greater<pair<int,int> >());
        
        int totalProfit=0;
        int count=0;
        for(int i=0;i<n;i++){
            int profit=v[i].first;
            int deadline=v[i].second;
            
            // chose last possible time for this job
            // Add time to set to keep track of taken times
            for(int j=deadline;j>0;j--){
                if(time.find(j)==time.end()){
                    time.insert(j);
                    totalProfit=totalProfit+profit;
                    count++;
                    break;
                }
            }
        }
        
        return {count,totalProfit};
    }
};