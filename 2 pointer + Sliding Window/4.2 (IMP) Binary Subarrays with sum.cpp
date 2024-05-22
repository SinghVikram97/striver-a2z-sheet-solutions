// https://leetcode.com/problems/binary-subarrays-with-sum/

// Brute force - O(n^2)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // sum is just the number of 1s
        int n=nums.size();
        int numOnes;
        int ans=0;
        for(int i=0;i<n;i++){
            numOnes=0;
            for(int j=i;j<n;j++){
                if(nums[j]==1){
                    numOnes++;
                }   
                if(numOnes==goal){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Subarray with given sum approach - prev question
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> myMap;
        myMap[0]=1;

        int currentSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            ans+=myMap[currentSum-goal];
            myMap[currentSum]++;
        }
        return ans;
    }
};

// Without Extra Space
// Find subarrays with sum which is atmost goal
// Find subarrays with sum whose sum is atmost goal-1

// subarrays with sum as goal =
// atMostSubarraySum(goal)-atMostSubarraySum(goal-1)


class Solution {
public:
    int atMostSubarraySum(vector<int>& nums, int goal){
        if(goal<0){
            return 0; // not possible
        }
        int n=nums.size();
        int left=0;
        int right=left;

        int ans=0;
        int sum=0;
        while(left<n && right<n){
            sum+=nums[right];
            right++;

            // if sum<=goal include it
            // num of subarrays ending at right
            // with <= sum
            // = length of subarray
            if(sum<=goal){
                ans+=(right-left);
            }
            else{
                while(sum>goal){
                    sum=sum-nums[left];
                    left++;
                }
                ans+=(right-left);
            }

        }

        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostSubarraySum(nums, goal)-atMostSubarraySum(nums, goal-1);
    }
};