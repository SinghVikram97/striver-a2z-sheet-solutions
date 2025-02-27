// https://leetcode.com/problems/longest-increasing-subsequence/submissions/

// dp[i] max subsequence length ending at i
// dp[i]=max(dp[i], 1+dp[j])
// where j<i and nums[j]<nums[i]
// ie. join nums[i] with existing subsequence ending at nums[j]
// it has to be increasing so nums[j]<nums[i]
// dp[i]=1 initially ie. number itself

// O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);

        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};

// [1, 7, 8, 3, 1, 4, 5]
/*
take 1 [1]
7>1 take 7 [1,7]
8>7 take 8 [1,7,8]
3<8 find position of 3 and replace with first element > 3 [1,3,8] 
1<8 find position of 1 and replace with first element >=1 or just ignore [1,3,8]
4<8 replace 8 with 4 [1,3,4]
5>4 [1,3,4,5]

Ans would be 4

Though the subsequence generated won't be correct but the answer would be correct
Since by replacing we are keeping our length intact but making room for more numbers to be included
*/
// O(nlogn)
class Solution {
public:
    void replace(vector<int> &ans, int x){
        // replace num just greater than x with x
        int start=0;
        int end=ans.size()-1;

        int upperBound=-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(ans[mid]==x){
                // ignore
                return;
            }else if(x<ans[mid]){
                // move left
                upperBound=mid;
                end=mid-1;
            }else{
                // move right
                start=mid+1;
            }
        }

        if(upperBound!=-1){
            ans[upperBound]=x;
        }
    }
    int lengthOfLIS(vector<int> & nums) {
        int n=nums.size();

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(nums[i]);
            }else{
                if(nums[i]>ans.back()){
                    // insert
                    ans.push_back(nums[i]);
                }else{
                    // replace element just greater than nums[i] with nums[i]
                    replace(ans, nums[i]);
                }
            }
        }

        return ans.size();
    }
};