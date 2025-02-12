// https://leetcode.com/problems/next-permutation/description/

// https://github.com/SinghVikram97/Interview-Prep/blob/master/IMP%20Questions/1.%20Next%20higher%20permutation%20or%20next%20higher%20no.cpp

/*
Example
9 8 7 6 3 5 4 1

We pick 3 since it is smaller than element on its right

Now we replace it with 4 ie. just bigger number
9 8 7 6 4 5 3 1

Now we sort or reverse numbers after 4
9 8 7 6 4 1 3 5
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return;
        }

        // Find element such that it is smaller than element on its right
        int index1=-1;
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                index1=i-1;
                break;
            }
        }
        if(index1==-1){
            sort(nums.begin(),nums.end());
            return;
        }

        // Find smallest possible element just bigger than this element
        int index2=index1+1;
        for(int i=index2;i<n;i++){
            if(nums[i]>nums[index1] && nums[i]<nums[index2]){
                index2=i;
            }
        }
        
        // Swap both indexes
        swap(nums[index1],nums[index2]);

        // Sort number after index1 to get smallest next permutation
        sort(nums.begin()+index1+1,nums.end());
        
    }
};