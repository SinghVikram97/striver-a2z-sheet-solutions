// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*

left = 2
right = 1

2 elements (root) 1 element


kth smallest k=6th 

left 4) root (right 1
left 2 root right 1

*/


class Solution {
public:
    // returns the number of nodes in tree rooted at root (including root)
    int kthSmallestHelper(TreeNode* root, int k, int &ans){
        if(root==NULL){
            return 0;
        }

        int leftNodes = kthSmallestHelper(root->left,k,ans);
        int rightNodes = kthSmallestHelper(root->right,k,ans);

        if(leftNodes>=k){
            kthSmallestHelper(root->left,k,ans);
        }

        else if(leftNodes==k-1){
            ans=root->val;
        }
        else if(leftNodes<k-1){
            kthSmallestHelper(root->right,k-leftNodes-1,ans);
        }

        return 1+leftNodes+rightNodes;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kthSmallestHelper(root,k,ans);
        return ans;
    }
};