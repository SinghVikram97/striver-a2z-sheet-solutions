// https://www.codingninjas.com/studio/problems/minimum-element-in-bst_8160462
int minVal(Node* root){
    if(root==NULL){
        return -1;
    }
    int mini = root->data;
    while(root->left!=NULL){
        root=root->left;
    }
    mini = root->data;
    return mini;
}