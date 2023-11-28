// https://leetcode.com/problems/count-complete-tree-nodes/
// in less than O(N)

/*

   18
  /  \
 15   30
 / \  /  \
40 50 100 40
/ \ /
8 7 9


*/

/*

We calculate the left height and right height 
here height is different

left height is keep going left, right height is keep going right
if left height = right height => PERFECT BINARY TREE , number of nodes 2^h-1
else number of nodes = nodes(left)+1+nodes(right)


height can be calculated in logn since we only move left or right
in worst case we will be calculating height for logn nodes
so time complexity is logn*logn

ex.

   18
  /  \
 15   30
 / \  /  \
40 50 100 40
/ \ /
8 7 9


18 left height = 4 , rh = 3

15, lh = 3 , rh = 2

now for 30 , lh = 1 , rh = 1 we don't need to go down, its a perfect tree so return 2^2-1 = 3

for 40 also lh=rh

for 50, lh=1 , rh=0

for 9 lh=0,rh=0
     

In worst case
   18
  /  \
 15   30
 / \  /  \
40 50 100 40
/ 
8 

we calculate height for all left nodes ie. 8, 15, 40, 8 logn nodes 
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        else if(root->left==NULL && root->right==NULL){
            return 1;
        }

        int leftHeight=getLeftHeight(root);
        int rightHeight=getRightHeight(root);

        if(leftHeight==rightHeight){
            return pow(2,leftHeight)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }

    int getLeftHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->left;
        }
        return count;
    }

    int getRightHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->right;
        }
        return count;
    }
};