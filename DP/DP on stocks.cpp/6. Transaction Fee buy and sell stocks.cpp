// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Recursion - TLE
class Solution {
public:
    int help(int i,bool allowedToBuy,vector<int> &prices, int fees){
        int n=prices.size();

        if(i>=n){
            return 0;
        }

        if(allowedToBuy){
            // 2 options

            // buy
            int op1=-prices[i]+help(i+1,!allowedToBuy,prices,fees);

            // don't buy
            int op2=help(i+1,allowedToBuy,prices,fees);
            return max(op1,op2);
        }else{
            // sell-> charge fees
            int op1=(prices[i]-fees)+help(i+1,!allowedToBuy,prices,fees);
            // don't sell
            int op2=help(i+1,allowedToBuy,prices,fees);
            return max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        return help(0,true,prices,fee);
    }
};

// Memo 
class Solution {
public:
    int help(int i,bool allowedToBuy,vector<int> &prices, int fees, vector<vector<int> > &dp){
        int n=prices.size();

        if(i>=n){
            return 0;
        }

        if(dp[i][allowedToBuy]!=-1){
            return dp[i][allowedToBuy];
        }

        if(allowedToBuy){
            // 2 options

            // buy
            int op1=-prices[i]+help(i+1,!allowedToBuy,prices,fees,dp);

            // don't buy
            int op2=help(i+1,allowedToBuy,prices,fees,dp);
            return dp[i][allowedToBuy]=max(op1,op2);
        }else{
            // sell-> charge fees
            int op1=(prices[i]-fees)+help(i+1,!allowedToBuy,prices,fees,dp);
            // don't sell
            int op2=help(i+1,allowedToBuy,prices,fees,dp);
            return dp[i][allowedToBuy]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int> > dp(n+5,vector<int>(2,-1));
        return help(0,true,prices,fee,dp);
    }
};