// https://leetcode.com/problems/snakes-and-ladders/description/

// BFS - convert to 1 board
// TLE - Without visited
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<int> v;

        // convert to a single 1d array
        // we have to move from [m-1,0] to [0,0] in minimum moves
        int index=0;
        for(int i=m-1;i>=0;i--){
            if(index%2==0){
                for(int j=0;j<n;j++){
                    v.push_back(board[i][j]);
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    v.push_back(board[i][j]);
                }
            }
        }

        int n2=m*n;
        // now we have to move from 0 to n2-1
        queue<int> mq;
        mq.push(0);
        int moves=0;
        while(!mq.empty()){
            int sizeQ=mq.size();
            for(int i=0;i<sizeQ;i++){
                int curPos=mq.front();
                mq.pop();

                if(curPos>=n2-1){
                    return moves;
                }

                // can move to 1-6 
                for(int j=1;j<=6;j++){
                    if(curPos+j<=n2-1){
                        int newPos=curPos+j;

                        if(v[newPos]==-1){
                            mq.push(newPos);
                        }else{
                            mq.push(v[newPos]-1); // 0 based indexing
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};

// Why we need visited to improve complexity and we don't need to explore again
/*
For example if snake at 17 and we return to 5 but from 1->5 one step and 5 already visited with less number of steps
We don't need to start again because we only need min moves
*/

// Final solution
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int n2 = m * n;

        vector<int> v;
        int index = 0;

        // Convert board to 1D array
        for (int i = m - 1; i >= 0; i--) {
            if (index % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    v.push_back(board[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    v.push_back(board[i][j]);
                }
            }
            index++;
        }

        vector<bool> visited(n2, false);
        queue<int> mq;
        mq.push(0);
        visited[0] = true;
        int moves = 0;

        while (!mq.empty()) {
            int sizeQ = mq.size();
            for (int i = 0; i < sizeQ; i++) {
                int curPos = mq.front();
                mq.pop();

                if (curPos == n2 - 1) {
                    return moves;
                }

                for (int j = 1; j <= 6; j++) {
                    int newPos = curPos + j;
                    if (newPos >= n2) break;

                    int finalPos = (v[newPos] == -1) ? newPos : v[newPos] - 1; // Convert 1-based to 0-based

                    if (!visited[finalPos]) {
                        visited[finalPos] = true;
                        mq.push(finalPos);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
