// https://leetcode.com/problems/max-consecutive-ones-iii/


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