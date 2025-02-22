// https://leetcode.com/problems/sudoku-solver/description/
class Solution {
public:
    bool canPlace(int rowNo, int colNo, vector<vector<char> > &board, char num){
        // check in same row
        for(int j=0;j<9;j++){
            if(board[rowNo][j]==num){
                return false;
            }
        }

        // check in same colmun
        for(int i=0;i<9;i++){
            if(board[i][colNo]==num){
                return false;
            }
        }

        // check 3*3 box
        int startRow=(rowNo/3)*3;
        int startCol=(colNo/3)*3;
        int endRow=startRow+3;
        int endCol=startCol+3;

        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
                if(board[i][j]==num){
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(int rowNo, int colNo, vector<vector<char> > &board){
        if(rowNo==9){
            return true;
        }

        if(colNo==9){
            // fill nextRow
            return solve(rowNo+1, 0, board);
        }

        if(board[rowNo][colNo]!='.'){
            // skip already filled
            return solve(rowNo,colNo+1,board);
        }

        // for each cell try numbers from 1 to 9
        for(int i=1;i<=9;i++){
            char number = '1' + (i-1);
            // If can place this number
            if(canPlace(rowNo, colNo, board, number)){
                // place this number
                board[rowNo][colNo]=number;
                // solve for next cell in same row
                // if all cells tried in same row , we move to next row
                if(solve(rowNo, colNo+1,board)){
                    return true;
                }
                board[rowNo][colNo]='.';
            }
        }
        
        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);   
    }
};