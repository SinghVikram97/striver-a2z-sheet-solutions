// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
// Inorder successor is the next greater element
// So either it will be the parent or the left most child of the right subtree of the node
class Solution{
  public:
    void findMinEle(Node* root,Node* &inS){
        while(root->left){
            root=root->left;
        }
        inS=root;
    }
    void helper(Node *root, Node *x, Node* &inS){
        if(root==NULL){
            return;
        }
        
        if(root->data==x->data){
            // least element in its right subtree
            if(root->right){
                findMinEle(root->right,inS);
            }
            return;
        }
        
        else if(x->data<root->data){
            inS=root; // greater so it can be an inorder sucessor
            helper(root->left,x,inS);
            return;
        }
        
        else{
            helper(root->right,x,inS);
            return;
        }
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node *inS=NULL;
       helper(root,x,inS);
       return inS;
    }
};