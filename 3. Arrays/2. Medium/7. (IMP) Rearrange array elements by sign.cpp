// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// We have to preserve order

/*
Example
3 1 10 -10 -5 -6

while traversing we find 1 here it should be a negative number we swap with next negative number -10
3 -10 10 1 -5 -6

now order of positive numbers get disturbed

So instead of that we find next negative number and right rotate array b/w current index and index of -ve number
3 -10 1 10 -5 -6
here order preserved
*/

/*
https://github.com/SinghVikram97/Interview-Prep/blob/master/IMP%20Questions/A_26%20(VIMP)%20Rearrange%20Positive%20Negative.cpp
*/


// TLE but without extra space
class Solution {
public:
    void rotate(vector<int> &v,int start,int end){
        // Store last element
        int last=v[end];
        // Shift other elements by one
        for(int i=end-1;i>=start;i--){
            v[i+1]=v[i];
        }
        // Insert last element at start
        v[start]=last;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i%2!=0 && nums[i]>=0){
                // find next negative integer
                int nextNegIndex=-1;
                for(int j=i+1;j<n;j++){
                    if(nums[j]<0){
                        nextNegIndex=j;
                        break;
                    }
                }

                if(nextNegIndex==-1){
                    // not possible
                    return {};
                }else{
                    // right rotate
                    rotate(nums, i, nextNegIndex);
                }
            }else if(i%2==0 && nums[i]<0){
                // find next positive integer
                int nextPositiveIndex=-1;
                for(int j=i+1;j<n;j++){
                    if(nums[j]>=0){
                        nextPositiveIndex=j;
                        break;
                    }
                }

                if(nextPositiveIndex==-1){
                    // not possible
                    return {};
                }else{
                    rotate(nums, i, nextPositiveIndex);
                }
            }
        }
        return nums;
    }
};