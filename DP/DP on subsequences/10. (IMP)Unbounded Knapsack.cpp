// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

// Recursion - TLE
int help(int i, int n, int maxWeight, vector<int> &profit, vector<int> &weight){
    if(i>=n){
        return 0;
    }

    // take
    int op1=0;
    if(maxWeight-weight[i]>=0){
        op1=profit[i]+help(i,n,maxWeight-weight[i],profit,weight);
    }

    // don't take
    int op2=help(i+1,n,maxWeight,profit,weight);

    return max(op1,op2);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return help(0,n,w,profit,weight);
}

// Memo
int help(int i, int n, int maxWeight, vector<int> &profit, vector<int> &weight, vector<vector<int> > &dp){
    if(i>=n){
        return 0;
    }

    if(dp[i][maxWeight]!=-1){
        return dp[i][maxWeight];
    }

    // take
    int op1=0;
    if(maxWeight-weight[i]>=0){
        op1=profit[i]+help(i,n,maxWeight-weight[i],profit,weight,dp);
    }

    // don't take
    int op2=help(i+1,n,maxWeight,profit,weight,dp);

    dp[i][maxWeight] = max(op1,op2);
    return dp[i][maxWeight];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int> > dp(n+1,vector<int> (w+5,-1));
    return help(0,n,w,profit,weight,dp);
}

// Can do in O(N) space complexity
// dp[i][j] = max value by picking items upto ith index and capacity is j
// dp[i][j] = max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]) // take or don't take

// Now for unbounded knapsack we can take any number of times multiple times
// dp[i][j] = max(value[i]+dp[i][j-weight][j], dp[i-1][j])