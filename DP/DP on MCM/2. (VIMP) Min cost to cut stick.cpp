// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// 1. sort the cuts
       // so that we don't have any overlapping subproblem
       // [3,5,1,4]
       // we can choose any as first cut
       // if we choose 5 
       // then solve for [3] and [1,4]
       // these overlap

       // now if we sort [1,3,5,6]
       // cut at 5
       // [1,3] and [6] both these cuts independent don't overlap

// 2. add 0 and length of stick to begining and end
// [0,1,3,5,6,9]

// answer = (cuts[j+1]-cuts[i-1])+minCost(i,k-1)+minCost(k+1,j)

// Recursion - TLE
class Solution {
public:
    int help(int i, int j, vector<int> cut){
        if(i>j){
            return 0;
        }

        int mini=INT_MAX-5;
        int lengthOfStick=cut[j+1]-cut[i-1];

        // cut can start from i to j
        for(int k=i;k<=j;k++){
            mini=min(mini, lengthOfStick+help(i,k-1,cut)+help(k+1,j,cut));
        }

        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
       sort(cuts.begin(),cuts.end());

       vector<int> cut;
       cut.push_back(0);

       for(int i=0;i<cuts.size();i++){
           cut.push_back(cuts[i]);
       }

       cut.push_back(n);

        // i will be 1
        // j will be cut.size()-2; // 2nd last element
       return help(1,cut.size()-2,cut);
    }
};

// Memo 

class Solution {
public:
    int help(int i, int j, vector<int> &cut, vector<vector<int> > &dp){
        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int mini=INT_MAX-5;
        int lengthOfStick=cut[j+1]-cut[i-1];

        // cut can start from i to j
        for(int k=i;k<=j;k++){
            mini=min(mini, lengthOfStick+help(i,k-1,cut,dp)+help(k+1,j,cut,dp));
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
       sort(cuts.begin(),cuts.end());

       vector<int> cut;
       cut.push_back(0);

       for(int i=0;i<cuts.size();i++){
           cut.push_back(cuts[i]);
       }

       cut.push_back(n);

        // i will be 1
        // j will be cut.size()-2; // 2nd last element

       vector<vector<int> > dp(cut.size()+5,vector<int>(cut.size()+5,-1));
       return help(1,cut.size()-2,cut,dp);
    }
};