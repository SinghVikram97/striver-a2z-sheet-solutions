// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        int maxRight=-1;
        
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxRight){
                ans.push_back(arr[i]);
            }
            maxRight=max(maxRight,arr[i]);
        }
        
        sort(ans.begin(), ans.end(), greater<int>());
        
        return ans;
    }
};