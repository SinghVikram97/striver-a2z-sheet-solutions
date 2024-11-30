// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

// Recursion - TLE
class Solution {
public:
    int help(vector<int> &cardPoints, int k, int left, int right){
        if(k==0){
            return 0;
        }

        // else pick from front or end
        int op1=INT_MIN;
        int op2=INT_MIN;

        int n=cardPoints.size();

        if(left<n){
            op1=cardPoints[left]+help(cardPoints,k-1,left+1,right);
        }
        if(right>=0){
            op2=cardPoints[right]+help(cardPoints,k-1,left,right-1);
        }
        return max(op1,op2);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return help(cardPoints,k,0,cardPoints.size()-1);
    }
};

// DP - MLE
class Solution {
public:
    int help(vector<int> &cardPoints, int k, int left, int right, vector<vector<int> > &dp){
        if(k==0){
            return 0;
        }

        int n=cardPoints.size();

        if(left<n && right>=0 && dp[left][right]!=-1){
            return dp[left][right];
        }


        // else pick from front or end
        int op1=INT_MIN;
        int op2=INT_MIN;

        if(left<n){
            op1=cardPoints[left]+help(cardPoints,k-1,left+1,right, dp);
        }
        if(right>=0){
            op2=cardPoints[right]+help(cardPoints,k-1,left,right-1, dp);
        }
        return dp[left][right]=max(op1,op2);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<vector<int> > dp(n,vector<int>(n,-1));
        return help(cardPoints,k,0,cardPoints.size()-1,dp);
    }
};

// Since we need maximum sum and we can pick from both ends
/*
Our ans subarray will contain parts from both starting and ending and the remaining array will always be contigous
ie. not some from front and some from end
So
We can find a subarray of size n-k with minimum sum
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int totalSum=0;
        
        for(int i=0;i<n;i++){
            totalSum+=cardPoints[i];
        }

        int K=n-k;

        int left=0;
        int right=0;

        int ans=INT_MAX-5;
        int sum=0;
 
        while(left<=right && right<n){
            // include right 
            sum=sum+cardPoints[right];
            int length=right-left+1;

            if(length>K){
                sum=sum-cardPoints[left];
                left++;

                // update ans
                ans=min(ans,sum);
                // move right
                right++;
            }else if(length<K){
                // increase window size
                right++;
            }else{
                // =k
                // update ans
                ans=min(ans, sum);
                // move right
                right++;
            }
        }

        return totalSum-ans;
    }
};