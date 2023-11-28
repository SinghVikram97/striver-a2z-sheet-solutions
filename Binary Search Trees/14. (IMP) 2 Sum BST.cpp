// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Naive solution - O(N) space
class Solution {
public:
    void inorderHelper(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }

        inorderHelper(root->left,ans);
        ans.push_back(root->val);
        inorderHelper(root->right,ans);
    }
    bool twoSum(vector<int> &v,int target){
        int i=0;
        int j=v.size()-1;

        while(i<j){
            if(v[i]+v[j]==target){
                return true;
            }
            else if(v[i]+v[j]<target){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderHelper(root,inorder);

        return twoSum(inorder,k);
    }
};

// Optimized Approach - O(h) space
// Use BST Iterator approach
// BST Iterator in previous approach gave next element in inorder while calling next()
// Develop a before() as well which traversed backward
// Solve using 2 pointer now

class Solution {
public:
    stack<TreeNode*> nextStack;
    stack<TreeNode*> beforeStack;

    void pushAllLeft(TreeNode* root){
        while(root){
            nextStack.push(root);
            root=root->left;
        }
    }

    void pushAllRight(TreeNode* root){
        while(root){
            beforeStack.push(root);
            root=root->right;
        }
    }

    TreeNode* getNext(){
        TreeNode* topEle = nextStack.top();
        nextStack.pop();
        pushAllLeft(topEle->right);
        return topEle;
    }

    bool hasNext(){
        if(!nextStack.empty()){
            return true;
        }
        return false;
    }

    TreeNode* getBefore(){
        TreeNode* topEle = beforeStack.top();
        beforeStack.pop();
        pushAllRight(topEle->left);
        return topEle;
    }

    bool hasBefore(){
        if(!beforeStack.empty()){
            return true;
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
       pushAllLeft(root);
       pushAllRight(root);

       TreeNode* left = getNext();
       TreeNode* right = getBefore();

       while(left->val < right->val){

            if(left->val+right->val==k){
                return true;
            }
            else if(left->val+right->val < k){
                if(hasNext()){
                    left = getNext();
                }
            }
            else{
                if(hasBefore()){
                    right = getBefore();
                }
            }
       }
       return false;
    }
};