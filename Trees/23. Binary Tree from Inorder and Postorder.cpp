// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// inorder -> left root right
// postorder -> left right root

class Solution {
public:
    TreeNode* helper(vector<int> inorder, vector<int> postorder){
        if(inorder.size()==0){
            return NULL;
        }

        if(inorder.size()==1){
            return new TreeNode(inorder[0]);
        }

        int n = postorder.size();

        int rootValue = postorder[n-1];
        
        vector<int> leftInorder;

        int i=0;
        while(i<n && inorder[i]!=rootValue){
            leftInorder.push_back(inorder[i]);
            i++;
        }

        // either i==n or inorder[i]==root
        // skip root
        i++;

        vector<int> rightInorder;
        while(i<n){
            rightInorder.push_back(inorder[i]);
            i++;
        }

        vector<int> leftPostOrder;
        vector<int> rightPostOrder;
        // calculate number of nodes in left subtree
        // add that number of nodes from post order
        int leftNodes = leftInorder.size();
        
        i=0;
        while(i<n-1 && i<leftNodes){
            leftPostOrder.push_back(postorder[i]);
            i++;
        }

        while(i<n-1){
            rightPostOrder.push_back(postorder[i]);
            i++;
        }

        TreeNode *root = new TreeNode(rootValue);
        TreeNode *left=buildTree(leftInorder, leftPostOrder);
        TreeNode *right=buildTree(rightInorder, rightPostOrder);

        root->left=left;
        root->right=right;

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       return helper(inorder,postorder);
    }
};