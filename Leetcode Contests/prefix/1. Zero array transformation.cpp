// https://leetcode.com/problems/zero-array-transformation-i/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        
        vector<int> indexFreq(n,0);
        
        for(int i=0;i<queries.size();i++){
            int leftIndex=queries[i][0];
            int rightIndex=queries[i][1];
            
            indexFreq[leftIndex]+=1;
            if(rightIndex+1<n){
                indexFreq[rightIndex+1]-=1;
            }
        }
        
        for(int i=1;i<n;i++){
            indexFreq[i]+=indexFreq[i-1];
        }
        
        bool allZero=true;
        for(int i=0;i<n;i++){
            if(indexFreq[i]>=nums[i]){
                
            }else{
                allZero=false;
            }
        }
        return allZero;
    }
};


// https://leetcode.com/problems/zero-array-transformation-ii/description/
// Binary search + above logic
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int endQueryIndex) {
        int n=nums.size();

        vector<int> indexFreq(n,0);
        
        for(int i=0;i<=endQueryIndex;i++){
            int leftIndex=queries[i][0];
            int rightIndex=queries[i][1];
            int val=queries[i][2];
            
            indexFreq[leftIndex]+=val;
            if(rightIndex+1<n){
                indexFreq[rightIndex+1]-=val;
            }
        }
        
        for(int i=1;i<n;i++){
            indexFreq[i]+=indexFreq[i-1];
        }
        
        bool allZero=true;
        for(int i=0;i<n;i++){
            if(indexFreq[i]>=nums[i]){
                
            }else{
                allZero=false;
            }
        }
        return allZero;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        
        bool allZero=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                allZero=false;
            }
        }
        
        if(allZero){
            return 0;
        }
        

        int start=0;
        int end=queries.size()-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            bool isPossible=isZeroArray(nums, queries, mid);

            if(isPossible){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        if(ans!=-1){
            return 1+ans;
        }else{
            return -1;
        }
    }
};