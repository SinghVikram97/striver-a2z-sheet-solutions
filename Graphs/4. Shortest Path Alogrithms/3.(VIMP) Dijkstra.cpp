// Toposort works for - acylic directed graphs ( toposort doesn't exist for undirected graphs/graphs with cycle)
// Dijkstra works for cyclic graphs too (with non negative weights)

// Toposort - O(V+E)
// Dijkstra - O(ElogV)

// Why Dijkstra doesn't work with negative weights?
// It will go into infinite loop, we keep traversing and distance becomes less every time

// 0 ----- 1  [ -2 as edge weight ]

// dist-> [0,INT_MAX]
// priority_queue -> {0,0}

// take out {0,0}, 0+(-2)= -2 <INT_MAX update dist and push into priority_queue
// dist -> [0,-2]
// priority_queue -> {-2,1}

// take out {-2,1}, dist[0] = -2-2 = -4 < 0 update dist and push into priority_queue
// dist [-4,-2]
// priority_queue -> {-4,0}

// goes on forever

// Time complexity using priority_queue

/* *************************************************************
Used to find shortest distance b/w source vertex and other vertices in undirected or directed graph with positive weights


IMP-> We do not need to keep track of whether a vertex is "done/finalized" ("visited") as in the Wikipedia description, 
      since re-reaching such a vertex will always fail the relaxation condition (when re-reaching a "done/finalized" vertex, 
      the new distance will never be less than it was originally), so it will be skipped anyway.
*************************************************************

DOESN'T WORK WITH NEGATIVE WEIGHTS
*************************************************************
Dijkstra relies on one "simple" fact: 
if all weights are non-negative, adding an edge can never make a path shorter.  (GREEDY ALGO)
That's why picking the shortest candidate edge (local optimality) always ends up being correct (global optimality).

If that is not the case, the "frontier" of candidate edges does not send the right signals;
a cheap edge might lure you down a path with positive weights while an expensive one hides a path with negative weights.
*************************************************************/

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// 1. Using Priority_Queue

// Distance array initially 0 for sourceVertex and INF for other
// When you find a dist < what is stored in distance array update distance and push it into pq as well
// So that you update distances when you take it out from pq
// pq stores {dist, node} and is a minimum priority queue (greedy algo)
// here distance is the DISTANCE FROM SOURCE
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int sourceVertex)
    {
        // we are given adjList
        // adj = {  {{1, 1}, {2, 6}}  , {{2, 3}, {0, 1}}  , {{1, 3}, {0, 6}}  }

        vector<int> dist(V, INT_MAX-5);
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;

        // dist from source vertex to source vertex will be 0
        dist[sourceVertex]=0;
        pq.push({0, sourceVertex});

        while(!pq.empty()){
            pair<int,int> topElePair=pq.top();
            pq.pop();

            int distanceTopEleFromSource=topElePair.first;
            int topEle=topElePair.second;

            // traverse the adjacency list of vertex and see if it reduces distance
            for(int i=0;i<adj[topEle].size();i++){
                int distTopEleToVertex=adj[topEle][i][1];
                int vertex=adj[topEle][i][0];

                int distFromSourceToVertex=distanceTopEleFromSource+distTopEleToVertex;

                
                if(distFromSourceToVertex<dist[vertex]){
                    // found a small distance update it
                    dist[vertex]=distFromSourceToVertex;
                    pq.push({distFromSourceToVertex, vertex});
                }
            }

        }

        return dist; 
    }
};
