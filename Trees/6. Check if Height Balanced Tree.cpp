// https://leetcode.com/problems/balanced-binary-tree/
class Solution {
public:
    // pair of height,true/false 
    pair<int,bool> isBalancedHelper(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }

        if(root->right==NULL && root->left==NULL){
            return {1,true};
        }

        pair<int,bool> leftHeight = isBalancedHelper(root->left);
        pair<int,bool> rightHeight = isBalancedHelper(root->right);

        int currentHeight = 1+max(leftHeight.first,rightHeight.first);
        int heightDiffSubTrees = abs(leftHeight.first-rightHeight.first);
        if(leftHeight.second==false || rightHeight.second==false){
            return {currentHeight,false};
        }
        else if(heightDiffSubTrees>1){
            return {currentHeight,false};
        }
        else{
            return {currentHeight,true};
        }
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).second;
    }
};