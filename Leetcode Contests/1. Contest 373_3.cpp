https://leetcode.com/contest/weekly-contest-373/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Form groups and sort indiviual groups
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        
        vector<pair<int,int> > v; // number,index
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        
        vector<int> ans(n);
        
        // 1. sort the array
        sort(v.begin(), v.end());
        
        // 2. Form group and sort indiviual group
        
        int i=0;
        while(i<n){

            vector<int> indices;
            int t=i;
            indices.push_back(v[i].second);
            
            // v[i+1] will always be greater since v is sorted
            while(i<n-1 && v[i+1].first-v[i].first<=limit){
                indices.push_back(v[i+1].second);
                i++;
            }

            
            // now sort the indices of a particular group
            sort(indices.begin(),indices.end());
            
            
            // Place elements at these indices in sorted order
            for(int j=0;j<indices.size();j++){
                ans[indices[j]]=v[t].first;
                t++; // t begins at i and ends with indices
            }
        
            
            i++;
        
        }
        return ans;
    }
};