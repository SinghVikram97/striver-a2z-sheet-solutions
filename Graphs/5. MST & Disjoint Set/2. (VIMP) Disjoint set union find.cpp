/*
1-2-3-4

5-6-7

Now if someone asks does 5 lie in the same component as 1?
You can do DFS O(E+V) and answer this -> BRUTE FORCE

Disjoint set can answer this in constant time

It has 2 main functions
1. findParent()
2. union() -> a. by rank , b. by size

Initially all nodes alone

when we connect 2 nodes we do it using union

Watch striver's video for intutition
*************
Union by rank

2 arrays rank and parent
Initially everyone parent of itself and rank of everyone is 0


*************
Union by size

2 arrays size and parent
Initially everyone parent of itself and size of everyone is 1


In both the unions we check rank/size of ultimate parent of both
And we try to minimize the impact of merge operation so we join smaller rank/size to bigger rank/size

We also do path compression but don't update rank/size since they are estimate rank is basically max possible height

IMP:
The point of both the union-by-rank heuristic and the union-by-size heuristic is to minimize the expected running time of the Merge operation. 
They are not intended for any other purpose.
*/


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
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
                // attach U to V
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
int main() {
    DisjointSet ds(7);
    
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    
    // If 3 and 7 in same component
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
    
    ds.unionByRank(3,7);
    
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    DisjointSet ds1(7);
    
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);
    
    // If 3 and 7 in same component
    if(ds1.findUltimateParent(3)==ds1.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
    
    ds1.unionByRank(3,7);
    
    if(ds1.findUltimateParent(3)==ds1.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    return 0;
}