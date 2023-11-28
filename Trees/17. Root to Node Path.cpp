// https://www.codingninjas.com/studio/problems/all-root-to-leaf-paths-in-binary-tree._983599


vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    if(root==NULL){
        return {};
    }
    if(root->left==NULL && root->right==NULL){
        return {to_string(root->data)};
    }

    vector<string> left=allRootToLeaf(root->left);
    vector<string> right=allRootToLeaf(root->right);

    vector<string> ans;
    string rootData=to_string(root->data);
    for(int i=0;i<left.size();i++){
        ans.push_back(rootData+" "+left[i]);
    }

    for(int i=0;i<right.size();i++){
        ans.push_back(rootData+" "+right[i]);
    }

    return ans;
}