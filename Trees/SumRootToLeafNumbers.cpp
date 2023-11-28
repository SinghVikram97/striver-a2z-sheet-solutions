// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:

    int traverseTree(TreeNode *root, int currentNumber) {

        if(root==NULL) {
            return 0;
        }

        if(root->left == NULL && root->right == NULL) {
            // 1*10+2= 12
            int newNumber = currentNumber*10 + root-> val;
            return newNumber;
        }

        int newNumber = currentNumber*10 + root-> val; // 4
        int leftSum = traverseTree(root->left, newNumber);
        int rightSum = traverseTree(root->right, newNumber);

        return leftSum+rightSum;

    }
    int sumNumbers(TreeNode* root) {
        return traverseTree(root,0);
    }
};
