// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    int daysTakenCalc(vector<int> &weights, int capacity, int days){
        int currentWeight=0;
        int daysAns=0;
        for(int i=0;i<weights.size();i++){
            // ship smaller than package size so not possible
            if(weights[i]>capacity){
                return INT_MAX-5;
            }
            if(currentWeight+weights[i]>capacity){
                // ship existing packages
                daysAns++;
                currentWeight=weights[i];
                if(daysAns>days){
                    // early exit
                    return INT_MAX-5; 
                }
            }else{
                currentWeight+=weights[i];
            }
        }
        // last package
        if(currentWeight){
            daysAns++;
        }
        return daysAns;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=1;
        int end=0;

        for(int i=0;i<n;i++){
            end+=weights[i];
        }

        // maximum capcity is all packages in 1 go ie. 1 day 
        
        int ans;
        while(start<=end){
            int mid=(start+end)/2;

            int daysTaken=daysTakenCalc(weights, mid, days);
            if(daysTaken<=days){
                // try to reduce capacity
                end=mid-1;
                ans=mid;
            }else{
                // increase taking more days
                start=mid+1;
            }
        }

        return ans;
    }
};