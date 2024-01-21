// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// for each element find the greatest element to its right, not including it as can't buy and sell on same day
// now substract greatest element to right - actual element
// return the max among them

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0 || n==1){
            return 0;
        }

        vector<int> greatestElementToRight(n,0);

        int maxi=0;

        for(int i=n-1;i>=0;i--){
            greatestElementToRight[i]=maxi;
            if(prices[i]>maxi){
                maxi=prices[i];
            }
        }

        

        int ans=0;

        for(int i=0;i<n;i++){
            ans=max(ans,greatestElementToRight[i]-prices[i]);
        }

        return ans;
    }
};

// We can optimise it as we don't need to store greatestElementToRight
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1){
            return 0;
        }

        int greatestElementToRight=0;
        int maxi=0;

        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, greatestElementToRight-prices[i]);
            greatestElementToRight=max(greatestElementToRight, prices[i]);
        }

        return maxi;
    }
};