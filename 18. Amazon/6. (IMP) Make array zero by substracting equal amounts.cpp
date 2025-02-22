// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description

// We want the number of steps to make every array element zero
// If 2 numbers are same they will turn 0 in same number of steps
// If 2 numbers diff they will turn 0 in diff number of steps
// So ans would be number of unique numbers
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> ms;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ms.insert(nums[i]);
            }
        }

        return ms.size();
    }
};