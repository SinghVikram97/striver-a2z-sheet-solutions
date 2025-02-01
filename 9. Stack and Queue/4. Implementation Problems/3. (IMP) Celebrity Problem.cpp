// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// Brute Force - O(N^2)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        int allZeroIndex=-1;
        
        for(int i=0;i<m;i++){
            bool allZero=true;
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0){
                    allZero=false;
                }
            }
            if(allZero){
                allZeroIndex=i;
                break;
            }
        }
        
        if(allZeroIndex==-1){
            return -1;
        }
        
        for(int i=0;i<m;i++){
            if(i!=allZeroIndex && mat[i][allZeroIndex]!=1){
                return -1;
            }
        }
        return allZeroIndex;
    }
};

// One more brute force form 2 arrays knowMe and Iknow
// For celebrity knowMe will be n-1 and Iknow will be 0

// WE can solve this using 2 points one pointer at top and another at bottom
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        int low=0;
        int high=m-1;
        
        while(low<high){
            if(mat[low][high]==1){
                // low knows high so low can't be celebrity
                low++;
            }else if(mat[high][low]==1){
                // high knows low so high can't be celebrity
                high--;
            }else{
                // if mat[low][high]=0 and mat[high][low]=0
                // ie. both don't know each other but celebrity know by everyone so neither of them celebrity
                low++;
                high--;
            }
        }
        
        if(low>high){
            return -1;
        }
        
        // verify that it is indeed celebrity
        // everyone know celebrity
        for(int i=0;i<m;i++){
            // i should know low ie. celebrity
            if(i!=low && mat[i][low]!=1){
                return -1;
            }
        }
        
        // celebrity doesn't know anyone
        for(int j=0;j<n;j++){
            if(mat[low][j]==1){
                return -1;
            }
        }
        
        return low;
    }
};