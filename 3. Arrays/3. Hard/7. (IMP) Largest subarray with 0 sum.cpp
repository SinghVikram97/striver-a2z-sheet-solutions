// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Same as 14th question in easy

/*
Using prefix sum technique
currentsum - some previous prefix = target sum
some previous prefix = current sum - target sum

we also store the index of some previous prefix to calculate length
*/
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
        
        unordered_map<int,int> mp; // sum, index
        mp[0]=-1;
        
        int targetSum=0;
        int currentSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            currentSum+=arr[i];
            int prevPrefixSum=currentSum-targetSum;
            
            if(mp.find(prevPrefixSum)!=mp.end()){
                ans=max(ans, i-mp[prevPrefixSum]);
            }
            
            // Only update if not already present as we want longest subarray
            if(mp.find(currentSum)==mp.end()){
                mp[currentSum]=i;
            }
        }
        
        return ans;
    }
};

// can't use sliding window here since we can negative numbers as well