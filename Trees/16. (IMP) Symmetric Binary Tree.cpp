// https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool help(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL || root2==NULL){
            return false;
        }

        if(root1->val==root2->val && help(root1->left,root2->right) && help(root1->right,root2->left)){
            return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return help(root,root);
    }
};