// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

// At each step can cut from 1 to remaining length
// need to return the max price

// TLE
int helper(int length,vector<int> &price){
    if(length==0){
        return 0;
    }

    int maxi=-1;
    for(int i=1;i<=length;i++){
        if(length-i>=0){
			// i-1 as 1 based indexing
            maxi=max(maxi, price[i-1]+helper(length-i,price));
        }
    }

    return maxi;
}
int cutRod(vector<int> &price, int n)
{
	return helper(n,price);
}

// DP
int helper(int length,vector<int> &price, vector<int> &dp){
    if(length==0){
        return 0;
    }

    if(dp[length]!=-1){
        return dp[length];
    }

    int maxi=-1;
    for(int i=1;i<=length;i++){
        if(length-i>=0){
			// i-1 as 1 based indexing
            maxi=max(maxi, price[i-1]+helper(length-i,price,dp));
        }
    }

    dp[length] = maxi;
    return dp[length];
}
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1,-1);
	return helper(n,price,dp);
}

