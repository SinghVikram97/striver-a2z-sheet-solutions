// https://www.codingninjas.com/studio/problems/sjf_1172165
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{
     // sort by arrival time and then burst time
    vector<pair<int,int> > jobs;

    for(int i=0;i<n;i++){
        jobs.push_back({arrivalTime[i],burstTime[i]});
    }

    sort(jobs.begin(), jobs.end());

    // All jobs in priority queue are in consideration
    // pair of burst time, arrival time, min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    // Push first job in pq
    pq.push(make_pair(jobs[0].second,jobs[0].first));
    int currentTime=jobs[0].first;
    int totalWaitTime=0;
    int i=1;
    while(!pq.empty()){

        pair<int,int> topEle=pq.top();
        pq.pop();

        // Waiting time
        totalWaitTime+=currentTime-topEle.second;
        // Time after executing this job
        currentTime+=topEle.first;

        // Push all jobs in consideration
        while (i < n && jobs[i].first <= currentTime) {
            pq.push({jobs[i].second,jobs[i].first});
            i++;
        }
    }

    return (float)totalWaitTime/n;
}