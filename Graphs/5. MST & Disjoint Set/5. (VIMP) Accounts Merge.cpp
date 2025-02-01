// https://leetcode.com/problems/accounts-merge/

// If same email and same name -> same person
// If same email and diff name -> not possible (invalid test case)
// If diff email and same name -> possible different person


/*
For each person assign an index ie. 0....
Now for each email we will store email, index

now if we see and email again in our map with different index
and these 2 emails belong to the same group so we do union(index1, index2)

now we traverse this map which has all the email, index
for each email we put map it to an index

and which index -> ultimateParent(index) for which that email is present for example

John -> [j1@gmail.com, j2@gmail.com]  0

John -> [j1@gmail.com, j3@gmail.com]  1

j1@gmail.com -> 0
j2@gmail.com -> 0

Now again we see j1@gmail.com so we merge 0 and 1

now j3@gmail.com we put -> 1

its okay to put 1 since when we traverse again we will check ultimateParent(1) which will be 0

Initially all parents of itself
*/
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        DisjointSet ds(n);

        // email, index
        unordered_map<string,int> mp;

        for(int i=0;i<accounts.size();i++){
            // start from 1 since 0 is the name
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];

                if(mp.find(email)==mp.end()){
                    mp[email]=i;
                }else{
                    int prevIndex=mp[email];
                    ds.unionByRank(i, prevIndex);
                    mp[email]=prevIndex;
                }
            }
        }

        vector<vector<string> > ans(n);
        
        for(auto it:mp){
            string email=it.first;
            int index=it.second;

            int ultimateParent=ds.findUltimateParent(index);

            ans[ultimateParent].push_back(email);
        }

        // Now some will be merged into other so ans will contain some names with empty list

        vector<vector<string> > finalAns;

        for(int i=0;i<n;i++){
            if(ans[i].size()!=0){
                // sort mails
                sort(ans[i].begin(), ans[i].end());

                vector<string> temp;

                // push name
                temp.push_back(accounts[i][0]);
                // push mails
                for(int j=0;j<ans[i].size();j++){
                    temp.push_back(ans[i][j]);
                }

                finalAns.push_back(temp);
            }
        }
    
        return finalAns;
    }
};