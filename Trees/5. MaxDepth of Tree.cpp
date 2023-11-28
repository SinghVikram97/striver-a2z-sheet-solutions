// https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            return 1;
        }

        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);

        return 1+max(leftDepth,rightDepth);
    }
};