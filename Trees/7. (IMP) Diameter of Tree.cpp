// https://leetcode.com/problems/diameter-of-binary-tree/

// diameter not necessarily through the root of the tree can contained in a subtree root 

// diameter = max of
// 1. height of leftSubtree + heightRightSubtree 
// 2. diameter of tree rooted at leftChild
// 3. diameter of tree rooted at rightChild

// need to return a pair
// pair<int,int> // height, diameter

class Solution {
public:
    pair<int,int> diameterHelp(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }

        if(root->left==NULL && root->right==NULL){
            return {1,1};
        }

        pair<int,int> leftSubtree = diameterHelp(root->left);
        pair<int,int> rightSubtree = diameterHelp(root->right);

        int heightOfCurrentNode = 1 + max(leftSubtree.first,rightSubtree.first);

        int diameterOfCurrentNode = max({leftSubtree.first+rightSubtree.first+1, leftSubtree.second, rightSubtree.second});

        return {heightOfCurrentNode, diameterOfCurrentNode};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelp(root).second-1; // we consider nodes, leetcode considers edges
    }
};