// https://leetcode.com/problems/task-scheduler/

// Greedy - finish element with most freq first

// Priority queue of element,freq

// insert in pq, take out most frequent element place it
// then remove it from pq for next n times ie. cycles of n+1 (place and then place n next elements)
// after than re insert everything again as now they can be considered again

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        int totalElements=tasks.size();
        for(int i=0;i<totalElements;i++){
            mp[tasks[i]]++;
        }

        priority_queue<pair<int,char> > pq;
        
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
       
        int ans=0;

        while(!pq.empty()) {
             // vector to store elements removed to add them later
            vector<pair<int,char> > tempList;

            // most freq task
            pair<int,char> topEle=pq.top();
            pq.pop();

            tempList.push_back({topEle.first-1,topEle.second}); // decrease freq

            // execute
            cout<<topEle.first<<" ";
            ans++;

            // can't execute topEle now till n more elements executed
            // execute them
            int N=n;

            while(N>0 && !pq.empty()){
                // most freq task
                pair<int,char> topEle=pq.top();
                pq.pop();

                tempList.push_back({topEle.first-1,topEle.second}); // decrease freq
                // execute
                cout<<topEle.second<<" ";
                ans++;
                // Decrease N
                N--;
            }

            // Now add back tasks since N complete
            for(int i=0;i<tempList.size();i++){
                pair<int,char> ele=tempList[i];
                if(ele.first>0){
                    pq.push({ele.first,ele.second});
                }
            }

            if(pq.empty()){
                // all jobs completed 
                break;
            }

            if(N>0){
                // no other option stay idle
                ans+=N;
            }
        }

        return ans;
    }
};