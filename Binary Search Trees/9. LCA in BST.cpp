// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Same as Binary Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if(root==p){
            return p;
        }

        if(root==q){
            return q;
        }

        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        if(left && right){
            return root;
        }

        if(left){
            return left;
        }

        if(right){
            return right;
        }

        return NULL;
    }
};

// BST SPECIFIC SOLUTION
// key 1 <= LCA <= key2

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        else if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};