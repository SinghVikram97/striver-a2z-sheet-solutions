// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        bool isAlternate=false;
        vector<vector<int> > ans;
        while(!myQueue.empty()){
            int size=myQueue.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode* current = myQueue.front();
                myQueue.pop();
                v.push_back(current->val);

                if(current->left!=NULL){
                    myQueue.push(current->left);
                }
                if(current->right!=NULL){
                    myQueue.push(current->right);
                }
            }
            if(isAlternate){
                reverse(v.begin(),v.end());
            }
            isAlternate=!isAlternate;
            ans.push_back(v);
        }

        return ans;
    }
};