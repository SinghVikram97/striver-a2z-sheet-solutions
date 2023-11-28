// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
       unordered_map<int,int> myMap;

       queue<pair<Node*,int> > myQueue;
       myQueue.push({root,0});

       int minDist=INT_MAX-5;
       int maxDist=INT_MIN+5;

       while(!myQueue.empty()){
            int size=myQueue.size();
            for(int i=0;i<size;i++){
                pair<Node*,int> frontNode=myQueue.front();
                myQueue.pop();

                Node *node = frontNode.first;
                int distance = frontNode.second;

                myMap[distance]=node->data;
                minDist=min(minDist, distance);
                maxDist=max(maxDist, distance);

                if(node->left){
                    myQueue.push({node->left,distance-1});
                }

                if(node->right){
                    myQueue.push({node->right,distance+1});
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