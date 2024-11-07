// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
class Solution {
public:
    int divisionResult(vector<int> &nums, int divisor, int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/divisor);
            if(sum>threshold){
                return sum;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // dividing by max number will give sum as 1
        // dividing by 1 will give sum as sum of all array numbers
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
        }

        int start=1;
        int end=maxi;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;

            int divisionResultSum=divisionResult(nums, mid, threshold);
            if(divisionResultSum>threshold){
                // make divisor bigger
                start=mid+1;
            }else{
                // it is smaller than threshold so acceptable
                // but make divisor even more smaller
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};