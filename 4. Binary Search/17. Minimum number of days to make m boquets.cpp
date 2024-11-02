// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    int bouquetNumber(vector<int> bloomDay, int days, int k, int m){
        int n=bloomDay.size();

        int count=0;
        int flowers=0;
        for(int i=0;i<n;i++){
            if(days>=bloomDay[i]){
                // bloomed
                flowers++;

                if(flowers==k){
                    // formed bouquet
                    count++;
                    flowers=0;

                    // we just need to know if number of boquets >= or < than m
                    // early exit
                    if(count>=m){
                        return count;
                    }
                }
            }else{
                flowers=0;
            }
        }

        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDay=-1;
        int n=bloomDay.size();

        for(int i=0;i<n;i++){
            maxDay=max(maxDay, bloomDay[i]);
        }

        // On maxDay every flower will be blooming

        int start=0;
        int end=maxDay;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;

            int boquetsPossible = bouquetNumber(bloomDay, mid, k, m);

            if(boquetsPossible>=m){
                // achieved our target
                // try to reduce days
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};