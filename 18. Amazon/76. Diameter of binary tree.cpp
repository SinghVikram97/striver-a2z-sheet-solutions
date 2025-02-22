// https://leetcode.com/problems/diameter-of-binary-tree/description/
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
        return diameterHelp(root).second-1;
    }
};