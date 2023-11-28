// https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067

// We can perform BFS starting from the start node
// But in tree we can only go down we need to go up as well

// So first have parent pointers in form of hashmap
#include<bits/stdc++.h>
void getStartNode(BinaryTreeNode<int>* root, int start, BinaryTreeNode<int>* &startNode){
    if(root==NULL){
        return;
    }

    if(root->data==start){
        startNode=root;
        return;
    }

    getStartNode(root->left,start,startNode);
    getStartNode(root->right,start,startNode);

}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Map from node to its parent
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> * > parentMap;

    queue<BinaryTreeNode<int> *> myQueue;
    myQueue.push(root);

    while(!myQueue.empty()){
        BinaryTreeNode<int> * frontNode = myQueue.front();
        myQueue.pop();

        if(frontNode->left){
            parentMap[frontNode->left]=frontNode;
            myQueue.push(frontNode->left);
        }

        if(frontNode->right){
            parentMap[frontNode->right]=frontNode;
            myQueue.push(frontNode->right);
        }
    }

    // Find start node
    BinaryTreeNode<int> * startNode;
    getStartNode(root,start,startNode);

    // Do BFS
    // 3 routes -> parent,left,right
    unordered_map<BinaryTreeNode<int> *,bool> isVisited;
    queue<BinaryTreeNode<int> *> bfsQueue;
    bfsQueue.push(startNode);
    isVisited[startNode]=true;

    int dist=-1;
    while(!bfsQueue.empty()){
        int size = bfsQueue.size();
        dist++;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> * frontNode = bfsQueue.front();
            bfsQueue.pop();

            // parent
            auto it = parentMap.find(frontNode);
            if(it!=parentMap.end()){
                BinaryTreeNode<int>* parentNode = parentMap[frontNode];
                if(!isVisited[parentNode]){
                    bfsQueue.push(parentNode);
                    isVisited[parentNode]=true;
                }
            }
            
            // left
            if(frontNode->left && !isVisited[frontNode->left]){
                bfsQueue.push(frontNode->left);
                isVisited[frontNode->left]=true;
            }
            // right
            if(frontNode->right && !isVisited[frontNode->right]){
                bfsQueue.push(frontNode->right);
                isVisited[frontNode->right]=true;
            }
        }
    }
    return dist;
}