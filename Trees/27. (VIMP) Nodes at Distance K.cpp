// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
public:

    void findNodesAtGivenDistance(TreeNode* root, int distance, vector<int> &result){
        if(root==NULL){
            return;
        }

        if(distance==0){
            result.push_back(root->val);
        }

        findNodesAtGivenDistance(root->left, distance-1, result);
        findNodesAtGivenDistance(root->right,distance-1,result);
    }
    
    int ans(TreeNode* root, TreeNode* target, int k, vector<int> &result){

        if(root==NULL || k<0){
            return -1;
        }

        if(root==target){
            findNodesAtGivenDistance(root,k,result);
            return 0;
        }

        int leftSubTree = ans(root->left,target,k,result);
        int rightSubTree = ans(root->right,target,k,result);

        if(leftSubTree!=-1){
            if(k==leftSubTree+1){
                result.push_back(root->val);
            }
            // find in the right subtree of node, as the target exists in left subtree 
            findNodesAtGivenDistance(root->right,k-leftSubTree-2,result);
            return 1+leftSubTree;
        }

        if(rightSubTree!=-1){
            if(k==rightSubTree+1){
                result.push_back(root->val);
            }
            // find in the left subtree of node, as the target exists in right subtree
            findNodesAtGivenDistance(root->left,k-rightSubTree-2,result);
            return 1+rightSubTree;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        ans(root,target,k,result);
        return result;
    }
};