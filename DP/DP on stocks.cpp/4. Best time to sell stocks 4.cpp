// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int help(int i, bool allowedToBuy, int cap, vector<int> &prices, vector<vector<vector<int> > > &dp){
        int n = prices.size();

        if(i==n || cap==0){
            // can't do any more transactions
            return 0;
        }

        if(dp[i][cap][allowedToBuy]!=-1){
            return dp[i][cap][allowedToBuy];
        }

        // if can buy then buy or don't buy
        if(allowedToBuy){
            // buy
            int op1=-prices[i]+help(i+1,!allowedToBuy,cap,prices,dp);
            // don't buy
            int op2=help(i+1,allowedToBuy,cap,prices,dp);
            return dp[i][cap][allowedToBuy]=max(op1, op2);
        }
        else{
            // not allowed to buy
            // so can sell or don't sell
            // sell -> transaction complete
            int op1=prices[i]+help(i+1,!allowedToBuy,cap-1,prices,dp);

            // don't sell
            int op2=help(i+1,allowedToBuy,cap,prices,dp);
            return dp[i][cap][allowedToBuy]=max(op1, op2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        int cap = k; 
        bool allowedToBuy = 1; 

        vector<vector<vector<int> > > dp(n+5, vector<vector<int> > (cap+5,      vector<int>(5,-1)));
        return help(0, allowedToBuy, cap, prices, dp);
    }
};

// Table + Space Optimised
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int cap = k; // max 2 transactions
        bool allowedToBuy = 1; 


        vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (cap+1, vector<int>(2)));


        // base case if i==n ie. all elements over 
        for(int j=0;j<=cap;j++){
            for(int k=0;k<=1;k++){
                dp[n][j][k]=0;
            }
        }

        // base case cap==0 ie. all transactions exhausted
        for(int i=0;i<=n;i++){
            for(int k=0;k<=1;k++){
                dp[i][0][k]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            // j start from 1 as cap=0 is base case
            for(int j=1;j<=cap;j++){
                for(int k=0;k<=1;k++){
                    cout<<i<<" : "<<j<<" : "<<k<<" : "<<endl;
                    if(k==1){
                        dp[i][j][k]=max(-prices[i]+dp[i+1][j][0], dp[i+1][j][1]);
                    }
                    else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][j-1][1],dp[i+1][j][0]);
                    }
                }
            }
        }

        return dp[0][cap][1]; // index =0, cap=2, allowedToBuy=true
    }
};