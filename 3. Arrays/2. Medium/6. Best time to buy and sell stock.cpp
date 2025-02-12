// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxGreaterToRight = 0;
        int maxPrice = 0;
        for(int i=n-1;i>=0;i--){
            maxPrice = max(maxPrice, maxGreaterToRight-prices[i]);
            maxGreaterToRight = max(maxGreaterToRight, prices[i]);
        }
        return maxPrice;
    }
};