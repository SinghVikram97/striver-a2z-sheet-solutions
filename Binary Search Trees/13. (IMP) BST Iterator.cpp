// https://leetcode.com/problems/binary-search-tree-iterator/

// Naive approach - compute inorder 
// space complexity - O(N)
class BSTIterator {
public:
    vector<int> inorderTraversal;
    int pointer=-1;
    void inOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root,inorderTraversal);
    }
    
    int next() {
        pointer++;
        return ans[pointer];
    }
    
    bool hasNext() {
        if(pointer>=inorderTraversal.size()){
            return false;
        }
        return true;
    }
};

// Optimized Approach 
// Space Complexity - O(H)
// Using Iterative Inorder
// push all elements going left in stack
// when taking out element push its right child + all elements in its left to the stack

class BSTIterator {
public:
    stack<TreeNode*> myStack;
    void pushAllLeft(TreeNode *root){
        while(root){
            myStack.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* topEle=myStack.top();
        myStack.pop();

        pushAllLeft(topEle->right);

        return topEle->val;
    }
    
    bool hasNext() {
        if(!myStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
