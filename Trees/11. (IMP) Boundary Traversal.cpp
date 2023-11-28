// https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void printLeftBoundary(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL){
        printLeftBoundary(root->left,ans);
    }
    else if(root->right!=NULL){
        printLeftBoundary(root->right,ans);
    }
}

void printRightBoundary(TreeNode<int> *root, vector<int> &ans){
     if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right!=NULL){
        printRightBoundary(root->right,ans);
    }
    else if(root->left!=NULL){
        printRightBoundary(root->left,ans);
    }
    ans.push_back(root->data);
}

void printLeafNodes(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    printLeafNodes(root->left,ans);
    printLeafNodes(root->right,ans);
}


vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
	printLeftBoundary(root->left,ans);
    printLeafNodes(root,ans);
    printRightBoundary(root->right,ans);
    return ans;
}

