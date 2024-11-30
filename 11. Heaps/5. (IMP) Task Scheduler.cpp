// https://leetcode.com/problems/task-scheduler/description/
/*
We need to execute most frequent task first
Use max heap
Execute each task then take it out of the queue and into some other store
After executing n times, add it back
*/
/*

A *** N tasks*** A

But for character after A

it can be

A B .. N-1 tasks .. B (incase A finished)

But that won't be possible because that would mean freq of B > freq of A and so B would be placed first
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        priority_queue<pair<int,char> > pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
        }

    
        int time=0;
        while(!pq.empty()){
            vector<pair<int,char> > tasksToAdd;

            pair<int,char> topEle=pq.top();
            pq.pop();

            // execute this task
            time++;

            if(topEle.first-1>0){
                tasksToAdd.push_back({topEle.first-1, topEle.second});
            }

            int N=n;
            // execute next n tasks
            while(N!=0 && !pq.empty()){
                pair<int,char> topEle=pq.top();
                pq.pop();

                // execute this task
                time++;

                if(topEle.first-1>0){
                    tasksToAdd.push_back({topEle.first-1, topEle.second});
                }

                N--;
            }

            // Add back all tasks to priority_queue
            for(int i=0;i<tasksToAdd.size();i++){
                if(tasksToAdd[i].first>0){
                    pq.push({tasksToAdd[i].first, tasksToAdd[i].second});
                }
            }

            if(pq.empty()){
                break;
            }

            // If n seconds not completed stay idle for remaining time
            // Note: We can add tasks before this if because we want to check if have any more tasks to execute after
            // If not we don't need to stay idle
            if(N>0){
                time=time+N;
            }

        }
        return time;
    }
};