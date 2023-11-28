// https://leetcode.com/problems/subarray-sum-equals-k/

// S[i...j]  = S[0.....j] - S[0.....i-1]
// k = sum - S[0.....i-1]
// S[0......i-1] = sum-k
// find count of all previous subarrays with sum = currentSum -k

// [1,2,-1,0,1,2,3], k=3
// currentSum
// [1,3,2,2,3,5,8]
// currentSum-k
// [-2,0,-1,-1,0,2(2 times),5 (1 time)]
// [1,2,-1][0,1,2]
// [1,2,-1,0][1,2]
// [1,2,-1,0,1,2][3]

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> myMap;
        // map sum to freq
        // insert 0,1 since subarray can start from 0th index
        myMap.insert({0,1});
        
        int currentSum=0;
        int countOfSubarrays=0;
        for(int i=0;i<n;i++){
            
            currentSum+=nums[i];
            
            countOfSubarrays+=myMap[currentSum-k];
            
            myMap[currentSum]++;
            
        }
    
        return countOfSubarrays;
    }
};