// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
class Solution {
public:
    void helper(TreeNode* root, TreeNode* &prev){
        if(root==NULL){
            return;
        }
        // pre - root,left,right
        TreeNode* tempStoringRightChild=root->right;
        if(prev!=NULL){
            tempStoringRightChild=root->right;
            prev->right=root;
        }
        prev=root;
        helper(root->left,prev);
        root->left=NULL;
        helper(tempStoringRightChild,prev);
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        helper(root,prev);
    }
};