// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// Same approach as strings/12 -> count number of substrings with k distinct characters
// subarrays with exactly k odd numbers = atMost(k)-atMost(k-1)
class Solution {
public:
    int atMost(vector<int> &nums, int k){
        if(k<0){
            return 0;
        }
        int n=nums.size();

        int left=0;
        int right=0;

        int ans=0;
        int oddCount=0;

        while(left<=right && right<n){
            if(nums[right]%2!=0){
                oddCount++;
            }

            if(oddCount<=k){
                // update ans
                ans+=right-left+1;
                // move right
                right++;
            }else{
                // shorten window
                while(left<=right && oddCount!=k){
                    if(nums[left]%2!=0){
                        oddCount--;
                    }
                    left++;
                }

                if(left>right){
                    right=left;
                }else if(oddCount==k){
                    // update ans
                    ans+=right-left+1;
                    // move right
                    right++;
                }
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        cout<<atMost(nums,k)<<" "<<atMost(nums,k-1)<<endl;
        return atMost(nums,k)-atMost(nums,k-1);
    }
};