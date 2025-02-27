// https://leetcode.com/problems/largest-divisible-subset/

// Same as LIS
// Largest subset from index i
// first sort in decreasing order
// ie. 10 5 2 so 10%5 ie. bigger%smaller can be 0

// now dp[i]=1+dp[j] if nums[i]%nums[j]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(), greater<int>());
        vector<int> dp(n,0);

        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<n;j++){
                if(nums[i]%nums[j]==0){
                   dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        int maxi=-1;
        int index;
        for(int i=0;i<n;i++){
          if(dp[i]>maxi){
            maxi=dp[i];
            index=i;
          }
        }

        // first element at index = i
        // next would be greatest dp[j] which can divide nums[i]
        int length = maxi-1; // length of subset is maxi
        vector<int> ans;
        ans.push_back(nums[index]);

        while(length>0){
          int maxi=-1;
          int nextIndex=-1;
          for(int j=index+1;j<n;j++){
              if(nums[index]%nums[j]==0 && dp[j]>maxi){
                 maxi=dp[j];
                 nextIndex=j;
              }
          }

          ans.push_back(nums[nextIndex]);
          index=nextIndex;
          length--;
        }

        cout<<maxi<<endl;
        return ans;
   
    }
};

// DP[i] num of numbers in largest subset ending at i
// IMP initialize DP[i] with 1
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sort 
        int n=nums.size();
        sort(nums.begin(), nums.end());

        // increasing order 1,2,3,4...
        // now for num[i] we have to check to the left
        // since bigger % smaller can be 0 only

        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }

        int maxEnd;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                maxEnd=i;
            }
        }

        cout<<maxi<<endl;

        vector<int> ans;
        ans.push_back(nums[maxEnd]);

        int curIndex=maxEnd;
        while(ans.size()!=maxi){
            // go to left and see what we would have picked
            int nextEle;
            int maxi=-1;

            for(int i=curIndex-1;i>=0;i--){
                if(nums[curIndex]%nums[i]==0 && dp[i]>maxi){
                    maxi=dp[i];
                    nextEle=i;
                }
            }

            ans.push_back(nums[nextEle]);
            curIndex=nextEle;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};