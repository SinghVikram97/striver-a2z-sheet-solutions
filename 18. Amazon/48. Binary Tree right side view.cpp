// https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        vector<int> ans;

        while(!myQueue.empty()){
            int size=myQueue.size();
            int currentLevelLastElement;
            for(int i=0;i<size;i++){
                TreeNode* frontEle=myQueue.front();
                myQueue.pop();

                currentLevelLastElement=frontEle->val;

                if(frontEle->left){
                    myQueue.push(frontEle->left);
                }
                if(frontEle->right){
                    myQueue.push(frontEle->right);
                }
            }
            ans.push_back(currentLevelLastElement);
        }
        return ans;
    }
};