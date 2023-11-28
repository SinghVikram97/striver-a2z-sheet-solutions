// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum._842494
// if we know sum1 we can calculate sum2 using total sum
// i we would need

// Recursion - TLE
int helper(int i,int sum1,vector<int> &arr,int n,int totalSum){
    if(i==n){
        int sum2=totalSum-sum1;
        return abs(sum1-sum2);
    }

    // 2 options

    // 1st subset
    int op1=helper(i+1,sum1+arr[i],arr,n,totalSum);

    // 2nd subset
    int op2=helper(i+1,sum1,arr,n,totalSum);

    return min(op1,op2);
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
	return helper(0,0,arr,n,totalSum);
}

// DP - WON'T work for non-negative integers as dp[i][sum] , sum can be negative in that case
int helper(int i,int sum1,vector<int> &arr,int n,int totalSum, vector<vector<int> > &dp){
    if(i==n){
        int sum2=totalSum-sum1;
        return abs(sum1-sum2);
    }

    if(dp[i][sum1]!=-1){
        return dp[i][sum1];
    }

    // 2 options

    // 1st subset
    int op1=helper(i+1,sum1+arr[i],arr,n,totalSum,dp);

    // 2nd subset
    int op2=helper(i+1,sum1,arr,n,totalSum,dp);

    int ans = min(op1,op2);
    dp[i][sum1]=ans;
    return ans;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    vector<vector<int> > dp(n,vector<int>(totalSum,-1));
	return helper(0,0,arr,n,totalSum,dp);
}