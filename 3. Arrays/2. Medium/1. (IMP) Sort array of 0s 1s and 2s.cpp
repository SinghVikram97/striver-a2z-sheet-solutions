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


// 2 pass - using wall idea
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // bring all zeroes to the front
        int zeroWall=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroWall++;
                swap(nums[zeroWall], nums[i]);
            }
        }

        // bring all ones to the front
        int oneWall=zeroWall;

        for(int i=oneWall+1;i<n;i++){
            if(nums[i]==1){
                oneWall++;
                swap(nums[oneWall], nums[i]);
            }
        }
    }
};

// Extending the above idea if fix 0 and 2 1 will be fixed
// We have two walls zeroWall and twoWall

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int cur=0;
        int zeroWall=-1;
        int twoWall=n;

        while(cur<twoWall){ // note <twoWall not n since numbers to right of twoWall have been processed as 2 already
            if(nums[cur]==0){
                zeroWall++;
                swap(nums[cur], nums[zeroWall]);
                cur++; // 
            }else if(nums[cur]==1){
                // do nothing
                // move right
                cur++;
            }else{
                // nums[cur] is 2
                twoWall--;
                swap(nums[cur], nums[twoWall]);
                // don't do cur++ since number we have swapped it with ie. we brought a number from right and put it in curr position
                // we want to process it 
            }
        }
    }
};