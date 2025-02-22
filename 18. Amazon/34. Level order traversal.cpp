// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }


        queue<TreeNode *> myQueue;
        myQueue.push(root);

        vector<vector<int> > ans;

        while(!myQueue.empty()){
            int size=myQueue.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode *front=myQueue.front();
                myQueue.pop();
                temp.push_back(front->val);

                if(front->left){
                    myQueue.push(front->left);
                }
                if(front->right){
                    myQueue.push(front->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

};