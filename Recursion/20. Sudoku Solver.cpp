// https://leetcode.com/problems/sudoku-solver/


class Solution {
public:

    bool isSafe(vector<vector<char> > &board, int row, int col, char number){
        // check row
        for(int i=0;i<9;i++){
            if(board[i][col]==number){
                return false;
            }
        }

        // check column
        for(int j=0;j<9;j++){
            if(board[row][j]==number){
                return false;
            }
        }

        // check 3*3 board
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        int endRow = startRow+3;
        int endCol = startCol+3;

        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
                if(board[i][j]==number){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char> > &board, int row, int col) {

        if(row==9){
            // end 
            return true;
        }

        if(col==9){
            return solve(board,row+1,0);
        }

        if(board[row][col]!='.'){
            return solve(board,row,col+1);
        }

        // For each cell try every number from 1 to 9
        for(int i=1;i<=9;i++){

            char number = '1' + (i-1);
            // check if its safe
            if(isSafe(board,row,col,number)){
                board[row][col]=number;

                // move right only when all finished move down
                if(solve(board,row,col+1)){
                    return true;
                }

                // backtrack
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};