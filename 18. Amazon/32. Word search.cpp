// https://leetcode.com/problems/word-search/description/
class Solution {
public:

    vector<vector<int> > dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool backtrack(vector<vector<char> > &board, 
        string word, 
        string currentWord, 
        vector<vector<bool> > &visited,
        int i,
        int j,
        int m,
        int n){
        
        if(currentWord == word) {
            return true;
        }

        if(i<0 || i>=m || j<0 || j>=n) {
            return false;
        }

        if(visited[i][j]){
            return false;
        }

        // check index of word we are exploring in this recursion
        int lengthCurrentWord = currentWord.length();
        // lets say word "abc" and currentWord "a"
        // we are exploring b
        // if board[i][j]!=b no need to traverse further

        // if lengthCurrentWord = 1 then we need to look if board[i][j] and word[lengthCurrentWord]
        
        if(board[i][j]!=word[lengthCurrentWord]){
            return false;
        }


        // mark as visited 
        visited[i][j]=true;

        // explore in all 4 directions
        for(int index=0;index<4;index++){
            int nextI = i + dir[index][0];
            int nextJ = j + dir[index][1];

            if(backtrack(board,word,currentWord+board[i][j],visited,nextI,nextJ,m,n)){
                return true;
            }                
        }

        // backtrack
        visited[i][j]=false;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n= board[0].size();
        vector<vector<bool> > visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtrack(board,word,"",visited,i,j,m,n)){
                    return true;
                }
            }
        }

        return false;
    }
};
