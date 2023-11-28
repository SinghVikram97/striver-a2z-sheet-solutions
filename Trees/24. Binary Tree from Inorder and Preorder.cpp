// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* helper(vector<int> preorder,vector<int> inorder){
        int n=preorder.size();

        if(n==0){
            return NULL;
        }

        if(n==1){
            return new TreeNode(preorder[0]);
        }

        vector<int> leftpreorder;
        vector<int> leftinorder;
        vector<int> rightpreorder;
        vector<int> rightinorder;

        int rootValue = preorder[0];

        int i=0;
        while(i<n && inorder[i]!=rootValue){
            leftinorder.push_back(inorder[i]);
            i++;
        }

        // skip root
        i++;

        while(i<n){
            rightinorder.push_back(inorder[i]);
            i++;
        }

        int numLeftSubtree=leftinorder.size();

        i=1;
        while(i<n && i<=numLeftSubtree){
            leftpreorder.push_back(preorder[i]);
            i++;
        }

        while(i<n){
            rightpreorder.push_back(preorder[i]);
            i++;
        }

        TreeNode *root=new TreeNode(rootValue);
        TreeNode *left = helper(leftpreorder,leftinorder);
        TreeNode *right = helper(rightpreorder,rightinorder);

        root->left=left;
        root->right=right;

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder);
    }
};