// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

// Brute Force - O(n^2)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size();

    long long int maxi=0;

    for(long long int i=0;i<n;i++){
        long long int sum=0;
        for(long long int j=i;j<n;j++){
            sum=sum+a[j];
            if(sum==k){
                maxi=max(maxi, j-i+1);
            }else if(sum>k){
                break;
            }
        }
    }

    return maxi;
}

// Using hashmap
/*
Same as previous question but here we store the index at which previous subarray ends
Also we don't the index if we encounter the sum again but at a different index
Since this index would be greater as we are moving to the right
We want to keep previous subarray as left as possible to have the current subarray as big as possible
*/
#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> nums, long long target) {
    int n=nums.size();

    unordered_map<long long int, long long int> mp;
    mp[0]=-1;
    long long int csum=0;
    long long int maxi=-1;

    for(int i=0;i<n;i++){
        csum+=nums[i];
        
        if(mp.find(csum-target)!=mp.end()){
            maxi=max(maxi, i-mp[csum-target]);
        }
        
        // Update only if new sum otherwise don't
        if(mp.find(csum)==mp.end()){
            mp[csum]=i;
        }
    }

    return maxi;
}

// 2 pointer