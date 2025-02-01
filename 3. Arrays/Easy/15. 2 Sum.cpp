// https://leetcode.com/problems/two-sum/

// Without sorting, using hashmap
// Time - O(N), Space - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap; // (number,index)

        for(int i=0;i<nums.size();i++){
            int remainingSum=target-nums[i];
            if(myMap.find(remainingSum)!=myMap.end()){
                return {i,myMap[remainingSum]};
            }
            myMap.insert({nums[i],i});
        }
        return {};
    }
};

// Sorting
// Time - O(nlogn), Space - O(1)
class Solution {
public:
    bool twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int start=0, end=nums.size()-1;

        while(start<end){
            int sum = nums[start]+nums[end];

            if(sum==target){
                return true;
            }
            else if(sum<target){
                // go right
                start++;
            }
            else{
                end--;
            }
        }
        return false;
    }
};