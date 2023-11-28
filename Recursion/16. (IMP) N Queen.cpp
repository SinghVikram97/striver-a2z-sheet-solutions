// https://leetcode.com/problems/n-queens/


// Imp - Since N queens and N rows
// Each row must contain 1 queen otherwise there will be one row with 2 queens which is not possible
// Pigenhole principle
class Solution {
public:

    vector<vector<int> > dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    bool isSafe(vector<string> &board,int i,int j,int n){
        // up 
        for(int row=i;row>=0;row--){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        // left up - negative 
        for(int row=i,col=j;row>=0 && col>=0;row--,col--){
            if(board[row][col]=='Q'){
                return false;
            }
        }

        // right up,row decrease, col increase
        for(int row=i,col=j;row>=0 && col<n;row--,col++){
            if(board[row][col]=='Q'){
                return false;
            }
        }


        return true;
    }

    void backtrack(int n, int i, vector<string> board,vector<vector<string> > &ans) {

        // reached end 
        if(i==n){
            ans.push_back(board);
            return;
        }

        // check for ith row
        // try to place in each column for ith row
        for(int j=0;j<n;j++){

            // check if safe
            if(isSafe(board, i, j, n)) {
                board[i][j]='Q';

                backtrack(n,i+1,board,ans);

                // backtrack

                board[i][j]='.';
            }
        }

        return;

    }

    vector<vector<string>> solveNQueens(int n) {
    
        vector<string>  board(n);
        string s="";
        for(int i=0;i<n;i++){
            s+=".";
        }
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<vector<string> > ans;

        // since every row must have a queen start from 0th row 
        backtrack(n, 0 , board, ans);

        return ans;

    }
};