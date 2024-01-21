// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int> > actualValue(n);
        
        for(int i=0;i<n;i++){
            actualValue[i]=make_pair(((double)arr[i].value/arr[i].weight),i);
        }
        
        sort(actualValue.begin(), actualValue.end(), [](const auto& x, const auto& y){return x.first > y.first;});

        
        int i=0;
        double ans=0;
        
        while(i<n && W>0){
            int index=actualValue[i].second;
            int weight=arr[index].weight;
            int value=arr[index].value;
        
            
            if(W-weight>=0){
                ans+=value;
                W=W-weight;
            }else{
                ans+=actualValue[i].first*W;
                W=0;
            }
            
            i++;
            
        }
        
        return ans;
        
    }
        
};