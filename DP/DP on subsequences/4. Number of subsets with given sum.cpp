// https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532

// Recursion - TLE
int helper(int i,int csum,int targetSum,vector<int> &arr){
    int n=arr.size();

    if(csum>targetSum){
        return 0;
    }

    if(csum==targetSum){
        return 1;
    }

    if(i>=n){
        return 0;
    }

    int op1=helper(i+1,csum+arr[i],targetSum,arr);
    int op2=helper(i+1,csum,targetSum,arr);
    return op1+op2;
}
int findWays(vector<int>& arr, int k)
{
	return helper(0,0,k,arr);
}

// Memo
#define m 1000000007
long long int helper(int i,int csum,int targetSum,vector<int> &arr,vector<vector<long long int> > &dp){
    int n=arr.size();

    if(csum>targetSum){
        return 0;
    }

    if(csum==targetSum){
        return 1;
    }

    if(i>=n){
        return 0;
    }

    if(dp[i][csum]!=-1){
        return dp[i][csum];
    }

    long long int op1=helper(i+1,csum+arr[i],targetSum,arr,dp);
    long long int op2=helper(i+1,csum,targetSum,arr,dp);
    long long int ans=((op1%m)+(op2%m))%m;
    dp[i][csum]=ans;
    return ans;
}
int findWays(vector<int>& arr, int k)
{
    int n=arr.size();
    vector<vector<long long int> > dp(n,vector<long long int>(k,-1));
	return helper(0,0,k,arr,dp);
}