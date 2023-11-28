// https://leetcode.com/problems/delete-node-in-a-bst/

// case 1 -> node without child -> simply make it numm
// case 2 -> node with single child -> replace with child
// case 3 -> node with both children -> replace with inorder successor ie. next minimum greater element in right subtree
// it will be right child or left most element in right subtree

class Solution {
public:
    TreeNode* getMin(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(key<root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }

        if(key>root->val){
            root->right = deleteNode(root->right,key);
            return root;
        }

        // key == root->val

        // case 1: node without child
        if(root->left==NULL && root->right==NULL) {
            return NULL; // new head
        }

        // case 2: node with a single child
        else if(root->left==NULL){
            root=root->right;
            return root;
        }

        else if(root->right==NULL){
            root=root->left;
            return root;
        }

        // case 3: node with both children -> replace with inorder successor ie. next minimum element 
        // ** inorder successor always in right substree so find next greater element in right subtree
        // it will be right child or left most element in right subtree
        // ie. minimum element in right subtree
        else {
            TreeNode *inorderSuccesor = getMin(root->right);
            int temp = root->val;
            root->val = inorderSuccesor->val;
            inorderSuccesor->val = temp;
            root->right = deleteNode(root->right,temp);
            return root;
        }

    }
};