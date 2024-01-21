// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// if next day stock decreases sell it if you have one
// if it increases buy one if you don't have one
// otherwise continue

// when stock descreases sell it
// for example
// 1->5->3 sell it at 5
// sum of local maxima > global maxima

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n==0 || n==1){
            return 0;
        }

        int ans=0;
        int currentStockValue=-1;

        for(int i=0;i<n-1;i++){
            if(prices[i+1]>=prices[i]){
                // continue 
                // but if not bought the stock buy it
                if(currentStockValue==-1){
                    currentStockValue=prices[i];
                }
            }
            else if(prices[i+1]<prices[i]){
                // sell the stock if bought
                if(currentStockValue!=-1){
                    ans+=prices[i]-currentStockValue;
                    // sell -> no stock now
                    currentStockValue=-1;
                }
            }
        }

        if(currentStockValue!=-1){
            // sell on last day
            ans+=prices[n-1]-currentStockValue;
        }

        return ans;
    }
};