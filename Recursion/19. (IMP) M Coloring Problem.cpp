// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// In bipartite graph 2 colors

// here M colors

// for every node try every possible color if not able to find any return false


// Time complexity: for every node N, M colors O(N*M)*N for isSafe function

class Solution{
public:
   bool isSafe(bool graph[101][101], int numNodes, int currentNode, int color, vector<int> colorsArray) {
        
        for(int i=0;i<numNodes;i++){
            if(graph[currentNode][i]==1 && colorsArray[i]==color){
                return false;
            }
        }
        return true;
    }

    bool canColor(bool graph[101][101], int currentNode, int numColors, int numNodes, vector<int> colorsArray) {
        if(currentNode==numNodes){
            return true;
            // reached end, colored every node
        }

        // color 1 to color numColors
        for(int i=1;i<=numColors;i++) {
            if(isSafe(graph,numNodes,currentNode,i,colorsArray)) {

                // mark this node with i color
                colorsArray[currentNode]=i;

                if(canColor(graph,currentNode+1,numColors,numNodes,colorsArray)){
                    return true;
                }

                // backtrack
                colorsArray[currentNode]=0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int numColors, int numNodes) {
        // nodes from 0 to numNodes-1
        // if graph[i][j]=true it means edge 

        vector<int> colorsArray(numNodes,0);

        if(canColor(graph, 0, numColors, numNodes, colorsArray)){
            return true;
        }
        else{
            return false;
        }
        
    }
};