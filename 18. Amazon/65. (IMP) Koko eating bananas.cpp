// https://leetcode.com/problems/koko-eating-bananas/description/

// Only imp thing is early exit

class Solution {
public:
    int findHours(vector<int> &piles, int h, int k){
        int n=piles.size();

        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil((double)piles[i]/k); // ex 7,4 -> 7/4=1.x -> 2 hours

            // Early exit -> otherwise overflow
            if(ans>h){
                return INT_MAX;
            }
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1;
        int n=piles.size();

        for(int i=0;i<n;i++){
            maxi=max(maxi, piles[i]);
        }

        long long int start=1;
        long long int end=maxi;

        long long int ans=-1;
        while(start<=end){
            long long int mid=(start+end)/2;

            long long int hours=findHours(piles, h, mid);
            if(hours<=h){
                // possible
                ans=mid;
                // reduce as we want to find minimum
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};