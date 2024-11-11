// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    bool possible(vector<int> &v, int maxSum, int k){
        int currentSum=0;
        int currentArrays=1; // first subarray

        // maxSum=maximum sum of any subrray ie. largest sum among all subarrays
        for(int i=0;i<v.size();i++){
            if(v[i]>maxSum){
                return false;
            }

            if(currentSum+v[i]<=maxSum){
                currentSum+=v[i];
            }else{
                currentArrays++;
                if(currentArrays>k){
                    return false;
                }
                currentSum=v[i]; // start of new subarray
            }
        }
        cout<<currentArrays<<endl;
        return currentArrays<=k; 

        // since maxSum is upper limit we can decrease sum per array and generate more subarrays
        // so subarrays going belong k count can always be handled
        // but subarray count going above k can't be handled
        
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini=min(nums[i],mini);
        }

        int start=mini;
        int end=sum;

        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;

            if(possible(nums, mid, k)){
                ans=mid;
                // decrease max sum to minimize ans
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};