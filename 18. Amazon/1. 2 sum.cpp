// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap; // number, index
        for(int i=0;i<nums.size();i++){
            int remainingSum=target-nums[i];
            auto it = myMap.find(remainingSum);
            if(it!=myMap.end()){
                return {i,it->second};
            }
            myMap[nums[i]]=i;
        }
        return {};
    }
};