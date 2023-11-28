// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Same concept as diameter


class Solution {
public:
    // max leaf to node sum , maxSum of tree 
    pair<int,int> maxPathSumHelper(TreeNode *root){

        if(root==NULL){
            return {-1001,-1001};
        }


        pair<int,int> leftSubtree = maxPathSumHelper(root->left);
        pair<int,int> rightSubtree = maxPathSumHelper(root->right);

        int maxLeafToNodeSum = max({root->val,leftSubtree.first+root->val,rightSubtree.first+root->val}); 
        // 1st option of just root as negative numbers

        // 4 options 
        // 1. LeftSubtree contains maxSum
        // 2. RightSubtree contains maxSum
        // 3. leaf to root is maxSum
        // 4. leatLeaf to root and then root to rightLeaf is maxSum
        int maxSum = max({leftSubtree.second,rightSubtree.second,root->val+leftSubtree.first+rightSubtree.first, maxLeafToNodeSum});

        return {maxLeafToNodeSum, maxSum};
    }
    int maxPathSum(TreeNode* root) {
        return maxPathSumHelper(root).second;
    }
};