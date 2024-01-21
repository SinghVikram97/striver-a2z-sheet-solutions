// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// TLE
class Solution {
public:
    int help(int index, bool allowedToBuy, vector<int> &prices){
        int n=prices.size();

        if(index>=n){
            return 0;
        }

        if(allowedToBuy){
            // Buy
            int op1=-prices[index]+help(index+1,!allowedToBuy,prices);
            // Don't buy
            int op2=help(index+1,allowedToBuy,prices);
            return max(op1,op2);
        }
        else{
            // Sell
            // index+2 since you can't buy on next day
            int op1=prices[index]+help(index+2,!allowedToBuy,prices);
            
            // don't sell
            int op2=help(index+1,allowedToBuy,prices);
            return max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        return help(0,true,prices);
    }
};

// Memo
class Solution {
public:
    int help(int index, bool allowedToBuy, vector<int> &prices, vector<vector<int> > &dp){
        int n=prices.size();

        if(index>=n){
            return 0;
        }

        if(dp[index][allowedToBuy]!=-1){
            return dp[index][allowedToBuy];
        }

        if(allowedToBuy){
            // Buy
            int op1=-prices[index]+help(index+1,!allowedToBuy,prices,dp);
            // Don't buy
            int op2=help(index+1,allowedToBuy,prices,dp);
            return dp[index][allowedToBuy]=max(op1,op2);
        }
        else{
            // Sell
            // index+2 since you can't buy on next day
            int op1=prices[index]+help(index+2,!allowedToBuy,prices,dp);
            
            // don't sell
            int op2=help(index+1,allowedToBuy,prices,dp);
            return dp[index][allowedToBuy]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n+5,vector<int>(2,-1));
        return help(0,true,prices,dp);
    }
};