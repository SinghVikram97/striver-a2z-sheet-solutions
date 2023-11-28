// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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

                if(current->left){
                    myQueue.push(current->left);
                }
                if(current->right){
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