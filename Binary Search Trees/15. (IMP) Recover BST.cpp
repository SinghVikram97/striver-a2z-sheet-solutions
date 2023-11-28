// https://leetcode.com/problems/recover-binary-search-tree/


// * not necessary that elements swapped are adjacent in inorder traversal

/* 1. Incase the 2 elements swapped are not adjacent
1 2 3 4 5 6 7 

swap 2,6

1 6 3 4 5 2 7

2 pairs -> (6,3) and (5,2)

current < prev , first number is on left of the pair , second on right of the pair

*/
/* 2. Incase the 2 elements swapped are adjacent
1 2 3 4 5 6 7 

swap 3,4

1 2 4 3 5 6 7

1 pair -> (4,3)

current < prev , both the numbers

*/

/*

first store both pairs if we find one inequality incase we don't find another then both these numbers swapped
if we find the second then discard the second number

*/

class Solution {
public:
    void recoverTreeHelper(TreeNode* root, TreeNode* &prev, TreeNode* &number1, TreeNode* &number2){
        if(root==NULL){
            return;
        }

        recoverTreeHelper(root->left,prev,number1,number2);
        // do something
        if(prev!=NULL && root->val<prev->val){

            if(number1==NULL && number2==NULL){
                // haven't found anything
                number1=prev;
                number2=root;
            }
            else{
                number2=root; // root the second in second pair
            }
        }
        
        // set new prev
        prev=root;

        recoverTreeHelper(root->right,prev,number1,number2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *number1=NULL;
        TreeNode *number2=NULL;
        TreeNode *prev=NULL;
        recoverTreeHelper(root,prev,number1,number2);

        // swap both numbers
        int temp = number1->val;
        number1->val = number2->val;
        number2->val = temp;
    }
};