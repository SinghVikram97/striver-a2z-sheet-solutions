// https://leetcode.com/problems/edit-distance/

// word1 to word2

// dp[i][j]

// if word1[i]==word2[j]
// dp[i][j]=dp[i-1][j-1]

// else
// 3 options -> minimum

// Insert
// insert word2[j] in word1 so word2[j] taken care of
// dp[i][j]=1+dp[i][j-1]

// Delete
// delete word1[i] so word2[j] will try with next in string
// dp[i][j]=1+dp[i-1][j]


// Replace
// replace word1[i] so that it becomes equal to word2[j] so both become equal
// dp[i][j]=1+dp[i-1][j-1]

// base case
// dp[i][0]=m
// dp[0][j]=n

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        vector<vector<int> > dp(m+5,vector<int>(n+5,0));

        for(int i=0;i<=m;i++){
            dp[i][0]=i; //if second string empty only option to insert every character of first string  
        }

        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }

        return dp[m][n];
    }
};