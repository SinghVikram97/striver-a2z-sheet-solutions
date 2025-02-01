// https://leetcode.com/problems/sum-of-subarray-ranges

// Brute Force - O(n^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        long long ans=0;

        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;

            for(int j=i;j<n;j++){
                mini=min(nums[j],mini);
                maxi=max(nums[j],maxi);

                ans=ans+(maxi-mini);
            }
        }

        return ans;


    }
};

// Uses concept of question 6
// We find in how many arrays a given element minimum and maximum respectively
// Then for minimum count we add to ans with - sign
// For maximum count we add to ans with + sign
/*
For finding how many arrays in which it is maximum
array = [3,2,1,4]
index = [0,1,2,3]

find next greater element and previous greater element

For minimum find previous smaller element and next smaller element

Duplicates?
Handle duplicates same as before make one side equal 
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=n-1;i>=0;i--){
            while(!ms.empty() && v[i]>=v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=n;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    vector<int> previousGreaterOrEqualElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=0;i<n;i++){
            while(!ms.empty() && v[i]>v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=-1;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=n-1;i>=0;i--){
            while(!ms.empty() && v[i]<=v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=n;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    vector<int> previousSmallerOrEqualElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=0;i<n;i++){
            while(!ms.empty() && v[i]<v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=-1;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        vector<int> nge = nextGreaterElement(nums);
        vector<int> pge = previousGreaterOrEqualElement(nums);
        vector<int> nse = nextSmallerElement(nums);
        vector<int> pse = previousSmallerOrEqualElement(nums);

        long long int ans=0;
        for(int i=0;i<n;i++){
            // num of subarrays in which it is maximum
            long long int right=nge[i]-i;
            long long int left=i-pge[i];

            long long int maxiSub=left*right;

            // num of subarrays in which it is minimum
            right=nse[i]-i;
            left=i-pse[i];

            long long int miniSub=left*right;

            ans=ans+(nums[i]*maxiSub)-(nums[i]*miniSub);
        }

        return ans;


    }
};