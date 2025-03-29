// https://leetcode.com/problems/missing-number/
// Sum can overflow
// We can use xor
// Or we mark element as visited 
// if numbers b/w [1,n] we can mark visited by making it negative
// but if numbers b/w [0,n] we can mark visited by adding (n+1)

// [3,0,1]
//  0 1 2
// n=4
// [7,4,1]
// 7%4=3!=7 x
// 4%4!=0!=4 x
// 1%4=1=4 so number missing is 2

// number that is not modified is the ans
// [2,0,1]
//  0 1 2
// in this case all will be modified by default answer will be n = 3

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // numbers b/w [0,n]
        int n = nums.size();
        int increaseBy = n+1;

        for(int i=0;i<n;i++){
            int index = nums[i]%increaseBy;

            if(index<n){
                nums[index]+=increaseBy;
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if(nums[i]<increaseBy){
                return i;
            }
        }
        return ans;
    }
};

// OR

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // numbers b/w [0,n]
        int n = nums.size();
        int increaseBy = n+1;

        for(int i=0;i<n;i++){
            int index = nums[i]%increaseBy;

            if(index<n){
                nums[index]+=increaseBy;
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if(nums[i]%increaseBy==nums[i]){
                // not modified
                return i;
            }
        }
        return ans;
    }
};