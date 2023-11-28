// https://leetcode.com/problems/flood-fill/

class Solution {
public:

    vector<vector<int> > direction = {{0,-1},{0,1},{-1,0},{1,0}};
    void dfs(int x,int y, int m,int n, int color, vector<vector<int> > &image) {
        if(image[x][y]!=color){
            int prevColor=image[x][y];
            image[x][y]=color;

            // visit adjacent pixels with same color
            for(int i=0;i<4;i++){
                int a = x+direction[i][0];
                int b = y+direction[i][1];

                if(a>=0 && a<m && b>=0 && b<n && image[a][b]==prevColor){
                    dfs(a,b,m,n,color,image);
                }
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        // visited will be kept track by color
        dfs(sr,sc,m,n,color,image); 
        return image;
    }
};