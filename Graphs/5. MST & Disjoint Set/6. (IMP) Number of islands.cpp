// https://leetcode.com/problems/number-of-islands/

// Using DSU

// We convert (i,j) to a single number for dsu
// we lay numbers row wise

class DisjointSet{
    vector<int> rank, parent, size;

    public:
        DisjointSet(int n){
            // both 1 based and 0 based indexing

            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }


        int findUltimateParent(int node){
            if(parent[node]==node){
                // root
                return node;
            }else{
                // do path compression
                // find parent of its parent till we reach root
                return parent[node]=findUltimateParent(parent[node]);
            }
        }

        void unionByRank(int u, int v){
            int ultimateParentU = findUltimateParent(u);
            int ultimateParentV = findUltimateParent(v);

            if(ultimateParentU==ultimateParentV){
                // In same
                return;
            }

            // Only change rank if ranks equal
            // Otherwise we are attaching smaller to bigger so no effect to bigger
            if(rank[ultimateParentU]>rank[ultimateParentV]){
                // attach V to U so ultimateParent of V attaches to U
                parent[ultimateParentV]=ultimateParentU;
            }else if(rank[ultimateParentU]<rank[ultimateParentV]){
                // attach U to V
                parent[ultimateParentU]=ultimateParentV;
            }else{
                // ranks equal attach anyone to anyone
                // attach U to v
                parent[ultimateParentU]=ultimateParentV;
                // change rank
                rank[ultimateParentV]++;
            }
        }

        void unionBySize(int u, int v){
            int ultimateParentU = findUltimateParent(u);
            int ultimateParentV = findUltimateParent(v);

            if(ultimateParentU==ultimateParentV){
                // In same
                return;
            }

            if(size[ultimateParentU]>size[ultimateParentV]){
                // attach V to U
                parent[ultimateParentV]=ultimateParentU;
                size[ultimateParentU]+=size[ultimateParentV];
            }else{
                // no equal case separately we can do in single else condition
                // atach U to V

                parent[ultimateParentU]=ultimateParentV;
                size[ultimateParentV]+=size[ultimateParentU];
            }
        }
};
class Solution {
public:
    int getElementNumber(int row, int col, int m, int n){
        int number = (row*n)+(col);
        return number;
    }
    vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int totalElements = (m*n);

        DisjointSet ds(totalElements-1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    int elementNumber = getElementNumber(i,j,m,n);

                    // add edges to all 4 surrounding elements that are 1
                    for(int k=0;k<4;k++){
                        int newI = i + dir[k][0];
                        int newJ = j + dir[k][1];

                        if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]=='1'){
                            int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                            ds.unionByRank(elementNumber, neighbourElementNumber);
                        }
                    }
                }
            }
        }

        int components=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // IMP check for ultimate parents for element with number = 1
                // As for 0 they will be ultimate parent of itself but they not part of graph
                if(grid[i][j]=='1'){
                    int elementNumber = getElementNumber(i,j,m,n);

                    if(ds.findUltimateParent(elementNumber)==elementNumber){
                        components++;
                    }
                }
            }
        }

        return components;
    }
};