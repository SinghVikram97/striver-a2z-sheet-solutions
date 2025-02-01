// Dijkstra's Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms

// Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well

// Floyd Warshall's algorithm, we need to check every possible path going via each possible node

//  Until now, to store a graph we have used the adjacency list. 

// But in this algorithm, we are going to use the adjacency matrix method. 

/* How to detect negative cycle

If we find that the cost of reaching any node from itself is less than 0 then we have a negative cycle
Because it should be 0 
*/

/*
We can also use Dikjstra for this problem but if graph has negative cycle we can't
Otherwise
we will apply Dijkstra’s algorithm for every possible node to make it work like a multi-source shortest path algorithm 
like Floyd Warshall. The time complexity of Floyd Warshall is O(V3)
whereas if we apply Dijkstra’s algorithm for the same purpose the time complexity reduces to O(V*(E*logV)) (where v = no. of vertices). 

*/

/*
Try every possible path to reach from i to j
matrix[i][j] =min(matrix[i][j], matrix[i][k]+matrix[k][j]), where i = source node,
                  j = destination node and k = the node via which we are reaching from i to j.


Time complexity = O(V3)
Space complexity = O(1)
*/

// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // if there is no edge from i to j change -1 to INT_MAX / bigger number for our algo to work
        int n=matrix.size();

        for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1005; // INT_MAX leads to overflow while addition 
	                // which converts it to a negative number
	        }
	    }

        // try every possible path 
        // IMP: order of loop -> k, i, j
        // trying -> i, j, k gives wrong output
        for(int k = 0 ; k < n ; k++){
	        for(int i = 0 ; i < n ; i++){
	            for(int j =0 ; j< n; j++){
	               matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }

        // Update INT_MAX to -1 to indicate no path b/w those 2 vertices
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1005){
                    matrix[i][j]=-1;
                }
            }
        }
	}
};