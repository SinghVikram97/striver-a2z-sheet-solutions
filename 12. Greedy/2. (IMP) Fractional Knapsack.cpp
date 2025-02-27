// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Only imp because of custom compare logic

// See the value/wt ratio and sort in descending order
// We want to take package which provides most value per unit of weight

/*
    sort(wtRatio.begin(), wtRatio.end(), [](auto &a, auto &b){
            return a.first>b.first;
    });
*/
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int numItems=val.size();
        
        vector<pair<double,int> > wtRatio(numItems);
        
        for(int i=0;i<numItems;i++){
            wtRatio[i]={val[i]/(double)wt[i], i};
        }
        
        sort(wtRatio.begin(), wtRatio.end(), greater<pair<double,int> >());
        
        int index=0;
        double ans=0;
        for(int i=0;i<numItems;i++){
            pair<double,int> pp=wtRatio[i];
            
            int index=pp.second;
            
            int weight=wt[index];
            int value=val[index];
            
            int canTake=min(capacity, weight); 
            // if capacity less and weight more, we only take what we can take otherwise we take whole weight
            ans=ans+(canTake*pp.first); 
            capacity=capacity-canTake;
            
            if(capacity<=0){
                return ans;
            }
            
        }
        
        return ans;
    }
};