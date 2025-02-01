// https://leetcode.com/problems/making-a-large-island/description/

// MLE - Brute force, try every zero
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
    void help(int x, int y, DisjointSet ds, vector<vector<int>> grid, int &maxi){
        grid[x][y]=1;

        int m=grid.size();
        int n=grid[0].size();

        int elementNumber = getElementNumber(x,y,m,n);

        for(int k=0;k<4;k++){
            int newI = x + dir[k][0];
            int newJ = y + dir[k][1];

            if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                ds.unionByRank(elementNumber, neighbourElementNumber);
            }
        }

         // find size of largest component
        unordered_map<int,int> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    int ultimateParent = ds.findUltimateParent(elementNumber);

                    mp[ultimateParent]++;
                }
            }
        }


        for(auto it:mp){
            maxi=max(maxi, it.second);
        }
    }
    int getElementNumber(int row, int col, int m, int n){
        int number = (row*n)+(col);
        return number;
    }
    vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int totalElements = (m*n);

        DisjointSet ds(totalElements-1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    // add edges to all 4 surrounding elements that are 1
                    for(int k=0;k<4;k++){
                        int newI = i + dir[k][0];
                        int newJ = j + dir[k][1];

                        if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                            int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                            ds.unionByRank(elementNumber, neighbourElementNumber);
                        }
                    }
                }
            }
        }

        // find size of largest component
        unordered_map<int,int> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    int ultimateParent = ds.findUltimateParent(elementNumber);

                    mp[ultimateParent]++;
                }
            }
        }


        int maxi=-1;

        for(auto it:mp){
            maxi=max(maxi, it.second);
        }

        // try changing a zero to 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    help(i,j,ds, grid,maxi);
                }   
            }
        }

        return maxi;
    }
};



// Optimized
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
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int totalElements = (m*n);

        DisjointSet ds(totalElements-1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    // add edges to all 4 surrounding elements that are 1
                    for(int k=0;k<4;k++){
                        int newI = i + dir[k][0];
                        int newJ = j + dir[k][1];

                        if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                            int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                            ds.unionByRank(elementNumber, neighbourElementNumber);
                        }
                    }
                }
            }
        }

        // find size of largest component without changing anything

        // ultimate parent, size
        unordered_map<int,int> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    int ultimateParent = ds.findUltimateParent(elementNumber);

                    mp[ultimateParent]++;
                }
            }
        }


        int maxi=-1;

        for(auto it:mp){
            maxi=max(maxi, it.second);
        }

        // try changing a zero to 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    // see neighbours
                    // if we join i,j with other island size becomes larger
                    // we only to increase size incase of distinct islands / components
                    // see striver solution for edge case
                    unordered_set<int> ms;
                     for(int k=0;k<4;k++){
                        int newI = i + dir[k][0];
                        int newJ = j + dir[k][1];
 
                        if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                            int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                            int ultimateParent = ds.findUltimateParent(neighbourElementNumber);
                            ms.insert(ultimateParent);
                        }
                    }

                    // increase size 
                    int size=0;

                    for(auto it:ms){
                        size=size+mp[it];
                    }

                    size=size+1; // 1 for changed element

                    maxi=max(size,maxi);


                }   
            }
        }

        return maxi;
    }
};

// We can also make use of size array in our disjoint set instead of keeping a separate map for sizes of each component