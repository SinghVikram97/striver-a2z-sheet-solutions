// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


// [8,5,1,7,10,12]
// [root, elements less than root, elements greater than root]
class Solution {
public:
    TreeNode* bstHelper(vector<int> preorder){
        if(preorder.size()==0){
            return NULL;
        }

        if(preorder.size()==1){
            return new TreeNode(preorder[0],NULL,NULL);
        }

        int root = preorder[0];
        vector<int> left;
        vector<int> right;

        int index=1;

        while(index<preorder.size() && preorder[index]<root){
            left.push_back(preorder[index]);
            index++;
        }

        while(index<preorder.size()){
            right.push_back(preorder[index]);
            index++;
        }
        

        TreeNode* leftSubtree=bstFromPreorder(left);
        TreeNode* rightSubtree=bstFromPreorder(right);

        return new TreeNode(root,leftSubtree,rightSubtree);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstHelper(preorder);
    }
};