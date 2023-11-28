// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) {
            return NULL;
       }

       // If we reach the node itself.
       if(root==p || root==q){
         return root;
       } 

       TreeNode* presentInLeft = lowestCommonAncestor(root->left,p,q);
       TreeNode* presentInRight = lowestCommonAncestor(root->right,p,q);

       // If present on both sides root is the LCA
       if(presentInLeft && presentInRight){
        return root;
       }

       // If present on one side, return that side
       if(presentInLeft!=NULL){
        return presentInLeft;
       }

       if(presentInRight!=NULL){
        return presentInRight;
       }

       // If not present in both subtrees, return null
       return NULL;
    }
};