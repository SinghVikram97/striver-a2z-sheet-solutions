// https://leetcode.com/problems/sort-colors/

// sort - O(nlogn)

// count number of 0s,1s and 2s
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count={0,0,0}; 
        int n = nums.size();

        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }

        int i=0;
        while(count[0]){
            nums[i]=0;
            count[0]--;
            i++;
        }

        while(count[1]){
            nums[i]=1;
            count[1]--;
            i++;
        }

        while(count[2]){
            nums[i]=2;
            count[2]--;
            i++;
        }

    }
};

// 3 pointer solution without counting
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low=-1; // 0
        int high=n; // 2
        // if we move 0 and 2 to their places 1 automatically ends up in the middle
        int curr=0;

        // curr < high instead of n as after high we have 2s
        while(curr<high){
            if(nums[curr]==0){
                low++;
                swap(nums[low],nums[curr]);
                curr++;
            }
            else if(nums[curr]==1){
                // continue;
                curr++;
            }
            else if(nums[curr]==2){
                // 
                high--;
                swap(nums[curr],nums[high]);
                // curr++; we don't as the number that was picked up from end and put in current position.
                // it is yet to be processed. 
            }
        }

    }
};