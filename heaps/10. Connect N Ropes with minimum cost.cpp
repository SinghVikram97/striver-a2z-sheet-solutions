// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long int cost=0;
        while(pq.size()>=2){
            long long int a=pq.top();
            pq.pop();
            
            long long int b=pq.top();
            pq.pop();
            
            cost+=a+b;
            pq.push(a+b);
        }
        
        
        
        return cost;
    }
};