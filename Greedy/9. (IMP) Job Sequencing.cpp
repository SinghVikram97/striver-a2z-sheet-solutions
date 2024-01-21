// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Brute force - take last possible slot for job with maximum profit
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int> > jobs; // profit, deadline
        
        for(int i=0;i<n;i++){
            jobs.push_back(make_pair(arr[i].profit,arr[i].dead));
        }
        
        // sort by profit
        sort(jobs.begin(),jobs.end(), [](const auto &a, const auto &b){
            return a.first>b.first;
        });
        
        unordered_set<int> takenSlots;
        
        int numJobs=0;
        int totalProfit=0;
        
        for(int i=0;i<n;i++){
            // take last possible slot
            for(int j=jobs[i].second;j>=1;j--){
                if(takenSlots.find(j)==takenSlots.end()){
                    // take this slot
                    takenSlots.insert(j);
                    numJobs++;
                    totalProfit+=jobs[i].first;
                    break;
                }
            }
        }
        
        return {numJobs, totalProfit};
        
        
    } 
};

// Use array instead of set
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int> > jobs; // profit, deadline
        
        int maxDeadline=-1;
        for(int i=0;i<n;i++){
            jobs.push_back(make_pair(arr[i].profit,arr[i].dead));
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        // sort by profit
        sort(jobs.begin(),jobs.end(), [](const auto &a, const auto &b){
            return a.first>b.first;
        });
        
        vector<int> slots(maxDeadline+1,-1);
        
        int numJobs=0;
        int totalProfit=0;
        
        for(int i=0;i<n;i++){
            // take last possible slot
            for(int j=jobs[i].second;j>=1;j--){
                if(slots[j]==-1){
                    // take slot
                    slots[j]=1;
                    numJobs++;
                    totalProfit+=jobs[i].first;
                    break;
                }
            }
        }
        
        return {numJobs, totalProfit};
        
        
    } 
};