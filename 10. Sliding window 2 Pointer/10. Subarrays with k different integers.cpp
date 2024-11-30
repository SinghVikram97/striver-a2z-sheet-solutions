// https://leetcode.com/problems/subarrays-with-k-different-integers/description/10
class Solution {
public:
    int atMost(vector<int> &nums, int k){
        if(k==0){
            return 0;
        }
        int n=nums.size();

        int left=0;
        int right=0;

        int ans=0;
        unordered_map<int,int> mp;

        while(left<=right && right<n){
            mp[nums[right]]++;

            int diffCount=mp.size();

            if(diffCount<=k){
                ans=ans+(right-left+1);
                right++;
            }else{
                while(left<=right && mp.size()>k){
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0){
                        mp.erase(nums[left]);
                    }
                    left++;
                }

                if(left>right){
                    // restart window
                    right=left;
                }else if(mp.size()<=k){
                    ans=ans+(right-left+1);
                    right++;
                }
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atMost(nums,k)-atMost(nums,k-1);
    }
};