// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       if(root==NULL){
            return {};
        }

        queue<TreeNode * > mQ;
        mQ.push(root);
        vector<int> ans;

        while(!mQ.empty()) {
            int size = mQ.size();
            int maxi = INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode *current = mQ.front();
                mQ.pop();
                maxi=max(maxi, current->val);

                if(current->left){
                    mQ.push(current->left);
                }

                if(current->right){
                    mQ.push(current->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};