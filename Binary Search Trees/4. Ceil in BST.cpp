// https://www.codingninjas.com/studio/problems/ceil-from-bst_920464
void ceilHelper(BinaryTreeNode<int> *node, int x, int &ceil){
    if(node==NULL){
        return;
    }
    if(node->data>=x){
        ceil=min(ceil, node->data);
        ceilHelper(node->left, x, ceil);
    }
    else{
        ceilHelper(node->right,x,ceil);
    }

}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil=INT_MAX-5;
    ceilHelper(node, x, ceil);
    if(ceil==INT_MAX-5){
        ceil=-1;
    }
    return ceil;
}