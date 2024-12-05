// https://leetcode.com/problems/coin-change/description/

// Recursion - TLE
class Solution {

  public:
    int helper(vector<int> &coins, int sum){
        if(sum==0){
            return 0;
        }
        
        if(sum<0){
            return -1;
        }
        
        // at each step can take any coin
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int steps = helper(coins,sum-coins[i]);
            
            if(steps!=-1){
                ans=min(ans, 1+steps);
            }
        }
        
        if(ans==INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
    int minCoins(vector<int> &coins, int sum) {
        return helper(coins, sum);
    }
};

// DP - TLE
class Solution {
public:
    int help(vector<int> &coins, int amount, vector<long long int> &dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX-5;
        }
        cout<<amount<<endl;
        if(dp[amount]!=-1){
            return dp[amount];
        }

        long long int ans=INT_MAX-5;
        for(int i=0;i<coins.size();i++){
            long long int steps=help(coins, amount-coins[i], dp);

            if(steps!=INT_MAX-5){
                ans=min(ans, steps+1);
            }
        }

        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount+1, -1);
        long long int ans = help(coins, amount, dp);
        if(ans==INT_MAX-5){
            return -1;
        }else{
            return ans;
        }
    }
};

/*
Since at each step we consider every coin it is inefficient
*/

// Recursion -> take or don't take - TLE
class Solution {
public:
    int helper(vector<int> &coins, int amount, int index){
        int n=coins.size();

        if(amount==0){
            return 0;
        }

        if(amount<0 || index>=n){
            return INT_MAX;
        }

        // take or don't take
        int op1=helper(coins, amount-coins[index], index);
        if(op1!=INT_MAX){
            op1+=1;
        }

        // don't take
        int op2=helper(coins, amount, index+1);

        return min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = helper(coins, amount, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};


// DP - 2d DP
class Solution {
public:
    int helper(vector<int> &coins, int amount, int index, vector<vector<int> > &dp){
        int n=coins.size();

        if(amount==0){
            return 0;
        }

        if(amount<0 || index>=n){
            return INT_MAX;
        }

        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        // take or don't take
        int op1=helper(coins, amount-coins[index], index, dp);
        if(op1!=INT_MAX){
            op1+=1;
        }

        // don't take
        int op2=helper(coins, amount, index+1, dp);

        return dp[index][amount]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1,-1));
        int ans = helper(coins, amount, 0, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};

// Greedy
// Only works for indian currency
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n=coins.size();

        int ans=0;
        int index=0;
        while(amount!=0 && index<n){
            if(coins[index]<=amount){
                while(amount-coins[index]>=0){
                    amount=amount-coins[index];
                    ans++;
                }
                index++;
            }else{
                index++;
            }
        }

        if(amount==0){
            return ans;
        }
        return -1;
    }
};
