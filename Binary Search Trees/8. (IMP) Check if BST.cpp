// https://leetcode.com/problems/validate-binary-search-tree/

// root greater than max in left subtree
// root smaller than minimum in right substree

class Solution {
public:
    // isBST, minEle, maxEle
    pair<bool, pair<int,int> > isBST(TreeNode* root){
        if(root==NULL){
            return {true,{INT_MAX,INT_MIN}};
        }
        if(root->left==NULL && root->right==NULL){
            return {true, {root->val,root->val}};
        }

        pair<bool,pair<int,int> > leftSubtree = isBST(root->left);
        pair<bool,pair<int,int> > rightSubtree = isBST(root->right);

        int leftMax = leftSubtree.second.second;
        int rightMin = rightSubtree.second.first;

        cout<<leftMax<<" "<<rightMin<<endl;

        int rootMin = min({root->val,leftSubtree.second.first, rightSubtree.second.first});
        int rootMax = max({root->val,leftSubtree.second.second, rightSubtree.second.second});


        if(!leftSubtree.first || !rightSubtree.first){
            return {false, {rootMin,rootMax}};
        }
        else{
            if(root->val>leftMax && root->val<rightMin){
                return {true, {rootMin,rootMax}};
            } 
            else{
                return {false, {rootMin,rootMax}};
            }
        }

    }
    bool isValidBST(TreeNode* root) {
        return isBST(root).first;
    }
};

// nodes in left subtree have an upper limit of root->val
// nodes in right subtree have an lower limit of root->val

class Solution {
public:
    bool isBST(TreeNode* root, long long int lowerLimit, long long int upperLimit) {
        if(root==NULL){
            return true;
        }

        if(root->val<=lowerLimit || root->val>=upperLimit){
            return false;
        }
        return isBST(root->left, lowerLimit, root->val) 
        && isBST(root->right,root->val,upperLimit);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, (long long int)INT_MIN-5, (long long int)INT_MAX+5);
    }
};