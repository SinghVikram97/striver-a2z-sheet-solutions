// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // dist, list of nodes
        // return the first node
        unordered_map<int, int > myMap;

        queue<pair<Node *,int> > myQueue;

        myQueue.push({root,0});

        int minDist = INT_MAX-5;
        int maxDist = INT_MIN+5;

        while(!myQueue.empty()) {
            int size = myQueue.size();
            for(int i=0;i<size;i++){
                pair<Node*, int> front = myQueue.front();
                myQueue.pop();

                Node* frontNode = front.first;
                int dist = front.second;

                if(myMap.find(dist)==myMap.end()){
                    myMap[dist]=front.first->data;
                }
                
                minDist=min(minDist,dist);
                maxDist=max(maxDist,dist);

                if(frontNode->left){
                    myQueue.push({frontNode->left,dist-1});
                }

                if(frontNode->right){
                    myQueue.push({frontNode->right,dist+1});
                }
            }
        }

        vector<int> ans;
        for(int i=minDist;i<=maxDist;i++){
            ans.push_back(myMap[i]);
        }

        return ans;

    }

};
