// https://leetcode.com/problems/max-consecutive-ones-iii/

// Think of it like a sliding window with maximum zeroes allowed = k


// Max sized window with k number of zeroes
// Since k zeroes can be flipped so can treat them as 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int left=0;
        int right=0;

        int ans=0;
        int count0=0;
        while(left<=right && right<n){
            if(nums[right]==1){
                // update ans
                ans=max(ans, right-left+1);
                // extend window
                right++;
            }else{
                count0++;
                if(count0<=k){
                    // okay
                    // update ans
                    ans=max(ans, right-left+1);
                    // extend window
                    right++;
                }else{
                    // greater than k so reduce window size from left
                    // not left=right since right is our current element we don't want to remove it
                    while(left<right && count0!=k){
                        if(nums[left]==0){
                            count0--;
                        }
                        left++;
                    }

                    if(count0<=k){
                        // fixed so update ans
                        ans=max(ans, right-left+1);
                        // extend window
                        right++;
                    }else{
                        // not possible to fix -> IMP
                        // so ignore this element
                        right++;
                        left=right;
                    }
                }
            }
        }
        return ans;
    }
};

// Another approach where we first check before including a zero
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int left=0;
        int right=0;
        int zeroCount=0;
        int ans=0;

        while(left<=right && right<n){
            if(nums[right]==1){
                ans=max(ans, right-left+1);
                right++;
            }else if(nums[right]==0 && zeroCount<k){
                ans=max(ans, right-left+1);
                zeroCount++;
                right++;
            }else{
                // nums[right]=0 and zeroCount=k
                while(left<right && zeroCount==k){
                    if(nums[left]==0){
                        zeroCount--;
                    }
                    left++;
                }

                if(zeroCount<k){
                    ans=max(ans,right-left+1);
                    if(nums[right]==0){
                        zeroCount++;
                    }
                    right++;
                }else{
                    // =k
                    // try new window
                    left=right+1;
                    right=right+1;
                    zeroCount=0;
                }
            }
        }
        return ans;
    }
};