// https://leetcode.com/problems/binary-tree-preorder-traversal/

// root left right
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        vector<int> ans;

        ans.push_back(root->val);

        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }

        for(int i=0;i<right.size();i++){
            ans.push_back(right[i]);
        }

        return ans;
    }
};