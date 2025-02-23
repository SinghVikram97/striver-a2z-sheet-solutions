// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// VIMP : pass prev as reference
class Solution {
public:
    void help(TreeNode *root, TreeNode *&prev){
        if(root==NULL){
            return;
        }

        // root left right

        // since prev changes root->right 
        // store it for future
        TreeNode *rootRight=root->right;

        // connect prev->right to root
        if(prev!=NULL){
            rootRight=root->right;
            prev->right=root;
        }

        // update prev
        prev=root;

        help(root->left, prev);

        // set root->left as null
        root->left=NULL;

        // use original right
        help(rootRight, prev);
    }
    void flatten(TreeNode* root) {
        TreeNode *prev=NULL;
        help(root, prev);
    }
};