// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

// Priority queue in c++ allows duplicates 


// TC: O(n*logn)
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i=0;i<N;i++){
            pq.push({arr[i],i});
        }
        
        int counter=0;
        int prevValue=-1;
        
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            
            int value=p.first;
            int index=p.second;
            
            if(value!=prevValue){
                counter++;
                prevValue=value;
            }
            
            arr[index]=counter;
        }
        
        return arr;
    }

};
