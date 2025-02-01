// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

// starting k characters of standard dictionary

// [abc,baf, bbe] we can say a comes before b from 1st two
// for baf and bbe we can't say f comes before e as a<b so we break that comparison
// baf comes before bb as a < b can't say anything about f & e

// Invalid dictionary
// [abcd,abc] as in dictionary if both words same smaller word comes before
// [abc,baf,abc] cyclic a comes before b and then b comes before a
// topoSort not possible for this


class Solution{
    public:
    vector<int> topoSort(vector<vector<int> > &adj) {
        int n = adj.size();

        vector<int> indegree(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                // edge from i to adj[i][j]
                indegree[adj[i][j]]++;
            }
        }

        vector<int> topo;

        // push nodes with indegree 0 into queue
        queue<int> mq;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                mq.push(i);
                topo.push_back(i);
            }
        }

        while(!mq.empty()) {
            int front = mq.front();
            mq.pop();

            for(int i=0;i<adj[front].size();i++){
                int child = adj[front][i];
                indegree[child]--;
                if(indegree[child]==0){
                    mq.push(child);
                    topo.push_back(child);
                }
            }
        }

        return topo;
    }
    string findOrder(string dict[], int N, int K) {
        // build adjaceny list, denote a as 0, b as 1
        vector<vector<int> > adj(K); // k characters

        // dict = {"baa","abcd","abca","cab","cad"}
        for(int i=0;i<N-1;i++){
            // compare i and i+1
            string a = dict[i];
            string b = dict[i+1];

            // find first non-matching character
            int index = -1;
            int len = min(a.length(), b.length());

            for(int j=0;j<len;j++){
                if(a[j]!=b[j]){
                    index = j;
                    break;
                }
            }

            if(index == -1) {
                return ""; // not valid dictionary
            }

            // a comes before b
            // so edge b/w a[j] -> b[j]
            adj[a[index]-'a'].push_back(b[index]-'a');
        }

        // Do toposort
        vector<int> topo = topoSort(adj);

        if(topo.size()!=K){
            // cyclic depedency 
            return ""; // not valid dictionary
        }

        string ans="";
        for(int i=0;i<topo.size();i++){
            ans=ans+ char(topo[i]+'a');
        }
        
        return ans;

    }
};