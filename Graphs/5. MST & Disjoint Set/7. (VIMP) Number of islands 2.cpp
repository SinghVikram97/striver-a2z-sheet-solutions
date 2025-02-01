// https://www.naukri.com/code360/problems/number-of-islands-ii_1266048 

// TLE
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

int getElementNumber(int row, int col, int m, int n){
        int number = (row*n)+(col);
        return number;
}
vector<int> numOfIslandsII(int m, int n, vector<vector<int>> &q){
	vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};

	vector<vector<int> > grid(m,vector<int>(n,0));

	int totalElements=m*n;

	DisjointSet ds(totalElements-1);

	vector<int> ans;

	for(int qn=0;qn<q.size();qn++){
		int x=q[qn][0];
		int y=q[qn][1];

		// set it as 1
		grid[x][y]=1;

		int elementNumber = getElementNumber(x,y,m,n);

		// add an edge from this node to its neighbours
		for(int k=0;k<4;k++){
            int newI = x + dir[k][0];
            int newJ = y + dir[k][1];

            if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                ds.unionByRank(elementNumber, neighbourElementNumber);
            }
        }

		// Find number of components
		int components=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // IMP check for ultimate parents for element with number = 1
                // As for 0 they will be ultimate parent of itself but they not part of graph
                if(grid[i][j]==1){
                    int elementNumber = getElementNumber(i,j,m,n);

                    if(ds.findUltimateParent(elementNumber)==elementNumber){
                        components++;
                    }
                }
            }
        }

		ans.push_back(components);
	}
	return ans;
}


// Optimized
// We don't find number of islands in each query

// We check if i,j already 1 it means repeated query we don't do anythin
// Else we mark it as 1 and increase number of islands
// Now we see its adjacent edges which are 4
// For each we check if their ultimate parents are not same
// We do a union of them 
// And decrease the number of islands by 1 since now they have become same
// If ultimate parents already same then no need to decrease by 1

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

int getElementNumber(int row, int col, int m, int n){
        int number = (row*n)+(col);
        return number;
}
vector<int> numOfIslandsII(int m, int n, vector<vector<int>> &q){
	vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};

	vector<vector<int> > grid(m,vector<int>(n,0));

	int totalElements=m*n;

	DisjointSet ds(totalElements-1);

	vector<int> ans;

	int numIslands=0;

	for(int qn=0;qn<q.size();qn++){
		int x=q[qn][0];
		int y=q[qn][1];

		if(grid[x][y]==1){
			// already visited again same query
			ans.push_back(numIslands);
			continue;
		}

		// set it as 1
		grid[x][y]=1;

		numIslands++; // its ultimate parent of itself

		int elementNumber = getElementNumber(x,y,m,n);

		// add an edge from this node to its neighbours
		for(int k=0;k<4;k++){
            int newI = x + dir[k][0];
            int newJ = y + dir[k][1];

            if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]==1){
                int neighbourElementNumber = getElementNumber(newI, newJ, m, n);
                
                // If this neighbour already part of the island that current element part of no need to decrement numIslands
                // See next question for edge case
				if(ds.findUltimateParent(elementNumber)!=ds.findUltimateParent(neighbourElementNumber)){
					ds.unionByRank(elementNumber, neighbourElementNumber);
					numIslands--;
				}
            }
        }

		// Maybe the older island gets connected to the new element and new element becomes
		// the root so number of islands will remain same
		// doing this is wrong
		// if(ds.findUltimateParent(elementNumber)==elementNumber){
		// 	numIslands++;
		// }

		ans.push_back(numIslands);
	}
	return ans;
}