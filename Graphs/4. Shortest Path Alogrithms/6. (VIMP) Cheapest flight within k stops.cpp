// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// BFS + keep track of levels
// levels = steps
// stops is 1-steps
// 1 2 3 , here 2 levels and 1 stop
// 1 2 3 4, here levels 3 and stops 2

// But along with dist you need to store steps as well
// Since for next dist calculation you can't reach neighbour node in more than k steps

/*
We use the temp variable because it may be possible that we use relaxed distance again in the same loop which will increase the number of stops

ex. TC: 
n=4
[[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
src=0, dst=3 , k=1

queue has 0
queue has 1,2

now we take out 1, it updates distance of 2 since 0->1->2 less than 0->2
but it increases stops now 2->3 in 1 and we calculate dist[2] as one updated by 1 we took 1 stop + 1 stop at 2
ie. we relaxed edge and increased stops

so we need temp distance variable so we don't use updated distance to update distances at the same level
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int > > > adjList;

        for(int i=0;i<flights.size();i++){
            int src=flights[i][0];
            int dest=flights[i][1];
            int price=flights[i][2];

            adjList[src].push_back({dest,price});
        }

        queue<int> mq;
        vector<int> price(n, INT_MAX);
        
        mq.push(src);
        price[src]=0;

        int steps=0;
        while(!mq.empty() && steps<=k){
            int size=mq.size();

            // make temp copy of price
            vector<int> temp = price;
            for(int i=0;i<size;i++){
                int city=mq.front();
                mq.pop();

                for(int j=0;j<adjList[city].size();j++){
                    int neighbourCity=adjList[city][j].first;
                    int neighbourPrice=adjList[city][j].second;

                    // price to reach this neighbour from src
                    // price to reach currentCity + price from currentCity to neighbour
                    int priceFromSrc = price[city]+neighbourPrice; // take from price as temp might have updated stops

                    // comparison with temp since temp is local ans at this level we want to find less than this
                    if(priceFromSrc<temp[neighbourCity]){
                        temp[neighbourCity]=priceFromSrc; // update only in temp
                        mq.push(neighbourCity);
                    }
                }

            }

            steps++;

            price=temp;
        }

        return price[dst]==INT_MAX ? -1 : price[dst];
    }
};

// without temp array -> instead pushing only the node into the queue push steps,dist as well
// in a way storing local copy of dist like temp inside the node
// <=k+1 since we process till k+1th step allowed
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int > > > adjList;

        for(int i=0;i<flights.size();i++){
            int src=flights[i][0];
            int dest=flights[i][1];
            int price=flights[i][2];

            adjList[src].push_back({dest,price});
        }

        vector<int> dist(n, INT_MAX);

        // node, dist, steps
        queue<pair<int,pair<int,int> > > mq;

        mq.push({src, {0,0}});
        dist[src]=0;

        while(!mq.empty()){
            pair<int,pair<int,int> > frontEle=mq.front();
            mq.pop();

            int curNode = frontEle.first;
            int distCurNode = frontEle.second.first; // use this for calculation but dist array for final ans
            int stepsCurNode = frontEle.second.second;

            for(int i=0;i<adjList[curNode].size();i++){
                int neighbour=adjList[curNode][i].first;
                int distNeighbour=adjList[curNode][i].second;

                int distNeighbourFromSource = distCurNode+distNeighbour; // use distCurNode instead of from the array dist

                if(distNeighbourFromSource < dist[neighbour] && stepsCurNode+1<=k+1){
                    dist[neighbour]=distNeighbourFromSource; // update original
                    mq.push({neighbour, {distNeighbourFromSource, stepsCurNode+1}});
                }
            }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};


// Here Dijkstra won't work since we want minimum price with k stops
// there can be a path with intermediate greater price but down the line lesser price with the bound of k steps
