// https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        vector<int> ans;

        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }

        ans.push_back(root->val);

        for(int i=0;i<right.size();i++){
            ans.push_back(right[i]);
        }

        return ans;
    }
};