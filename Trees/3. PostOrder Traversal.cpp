// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        vector<int> ans;

        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }

        for(int i=0;i<right.size();i++){
            ans.push_back(right[i]);
        }

        ans.push_back(root->val);

        return ans;
    }
};