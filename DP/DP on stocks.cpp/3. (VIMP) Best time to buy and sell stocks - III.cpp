// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// TLE - Recursion
class Solution {
public:
    int help(int i, bool allowedToBuy, int cap, vector<int> &prices){
        int n = prices.size();

        if(i==n || cap==0){
            // can't do any more transactions
            return 0;
        }

        // if can buy then buy or don't buy
        if(allowedToBuy){
            // buy
            int op1=-prices[i]+help(i+1,!allowedToBuy,cap,prices);
            // don't buy
            int op2=help(i+1,allowedToBuy,cap,prices);
            return max(op1, op2);
        }
        else{
            // not allowed to buy
            // so can sell or don't sell
            // sell -> transaction complete
            int op1=prices[i]+help(i+1,!allowedToBuy,cap-1,prices);

            // don't sell
            int op2=help(i+1,allowedToBuy,cap,prices);
            return max(op1, op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // max 2 transactions
        bool allowedToBuy = 1; 
        return help(0, allowedToBuy, cap, prices);
    }
};

// DP - Memo - Accepted
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // max 2 transactions
        bool allowedToBuy = 1; 

        vector<vector<vector<int> > > dp(n+5, vector<vector<int> > (cap+5, vector<int>(5,-1)));
        return help(0, allowedToBuy, cap, prices, dp);
    }
};

// Tabulation

// dp[index][allowedToBuy][cap]

// 1. base case
/*
if cap==0
return 0

so dp[index][allowedToBuy][0]=0, indx -> 0 to n-1 and allowedToBuy -> 0 to 1

if index==n
return 0
dp[n][allowedToBuy][cap]=0

*/
/*
start from opposite
i -> n-1 to 0
buy -> 0 to 1
cap -> 0 to 1

*/

/*
ans-> dp[0][1][2] 
*/

/*

recurrence -> same


*/


// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // max 2 transactions
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
                    if(k==1){
                        dp[i][j][k]=max(-prices[i]+dp[i+1][j][0], dp[i+1][j][1]);
                    }
                    else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][j-1][1],dp[i+1][j][0]);
                    }
                }
            }
        }

        return dp[0][2][1]; // index =0, cap=2, allowedToBuy=true
    }
};

// Space Optimization
// since we are dependent on only dp[i+1]
// we can use current->i and after->i+1, 2 arrays
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // max 2 transactions
        bool allowedToBuy = 1; 

        vector<vector<int> > after(cap+1, vector<int>(2));
        vector<vector<int> > curr(cap+1, vector<int>(2));


        // base case if i==n ie. all elements over 
        // after as 0
        for(int j=0;j<=cap;j++){
            for(int k=0;k<=1;k++){
                after[j][k]=0;
            }
        }

        // base case cap==0 ie. all transactions exhausted
        for(int k=0;k<=1;k++){
            after[0][k]=0;
        }
        

        for(int i=n-1;i>=0;i--){
            // j start from 1 as cap=0 is base case
            for(int j=1;j<=cap;j++){
                for(int k=0;k<=1;k++){
                    if(k==1){
                        curr[j][k]=max(-prices[i]+after[j][0], after[j][1]);
                    }
                    else{
                       curr[j][k]=max(prices[i]+after[j-1][1],after[j][0]);
                    }
                }
            }
            after=curr;
        }

        return after[2][1]; // index =0, cap=2, allowedToBuy=true
    }
};