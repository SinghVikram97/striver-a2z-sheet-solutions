// https://leetcode.com/problems/surrounded-regions/

// A boundary O can't be surrounded by X on all sides

// So if a O connected to a boundary O there is no chance that it can be surrounded by X on all sides

// So start dfs from boundary Os and mark Os connected to them as visited [only O will be neighbours]

// The unvisited Os will be surrounded by X on all sides 


class Solution {
public:

    vector<vector<int> > dir = { {-1,0} , {1,0}, {0,-1}, {0,1} };

    void dfsUtil(int startI, int startJ, int m, int n, vector<vector<char> > &board, vector<vector<bool> > &visited) {
        visited[startI][startJ]=true;

        // visit neighbouring Os
        for(int i=0;i<4;i++){
            int a = dir[i][0]+startI;
            int b = dir[i][1]+startJ;

            if(a>=0 && a<m && b>=0 && b<n && board[a][b]=='O' && !visited[a][b]){
                dfsUtil(a,b,m,n,board,visited);
            }
        }

    }

    void dfs(int m, int n, vector<vector<char>> &board, vector<vector<bool> > &visited) {

        // first row
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !visited[0][j]){
                dfsUtil(0,j,m,n,board,visited);
            }
        }

        // last row
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O' && !visited[m-1][j]){
                dfsUtil(m-1,j,m,n,board,visited);
            }
        }

        // first column
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfsUtil(i,0,m,n,board,visited);
            }
        }

        // last column
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O' && !visited[i][n-1]){
                dfsUtil(i,n-1,m,n,board,visited);
            }
        }


    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool> > visited(m,vector<bool>(n));

        dfs(m, n, board, visited);

        // Mark unvisited O as X

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};