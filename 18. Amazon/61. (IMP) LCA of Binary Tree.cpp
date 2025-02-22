// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) {
            return NULL;
       }

       // If we reach the node itself.
       if(root==p || root==q){
         return root;
       } 

       TreeNode* presentInLeft = lowestCommonAncestor(root->left,p,q);
       TreeNode* presentInRight = lowestCommonAncestor(root->right,p,q);

       // If present on both sides root is the LCA
       if(presentInLeft && presentInRight){
        return root;
       }

       // If present on one side, return that side
       if(presentInLeft!=NULL){
        return presentInLeft;
       }

       if(presentInRight!=NULL){
        return presentInRight;
       }

       // If not present in both subtrees, return null
       return NULL;
    }
};

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
// Now here we don't have the root, but we have access to parent pointer

// Naive - find root and then solve using same logic as above
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lca(Node* root, Node* p, Node* q) {
       if(root==NULL) {
            return NULL;
       }

       // If we reach the node itself.
       if(root==p || root==q){
         return root;
       } 

       Node* presentInLeft = lca(root->left,p,q);
       Node* presentInRight = lca(root->right,p,q);

       // If present on both sides root is the LCA
       if(presentInLeft && presentInRight){
        return root;
       }

       // If present on one side, return that side
       if(presentInLeft!=NULL){
        return presentInLeft;
       }

       if(presentInRight!=NULL){
        return presentInRight;
       }

       // If not present in both subtrees, return null
       return NULL;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *temp=p;
        while(temp->parent!=NULL){
            temp=temp->parent;
        }

        Node *root=temp;
        return lca(root, p, q);
    }
};

// Efficient approach -> same as finding intersection point of 2 linked lists
// Find depth of both nodes p and q
// Then traverse diff in depth first
// Then both at same depth now what parent at depth = 0 will be the answer
class Solution {
public:
    int findDepth(Node *n){
        int depth=0;
        while(n->parent!=NULL){
            n=n->parent;
            depth++;
        }
        return depth;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int depthP=findDepth(p);
        int depthQ=findDepth(q);


        // Remove extra depth from node
        if(depthP>depthQ){
            int diff=depthP-depthQ;
            while(diff!=0){
                p=p->parent;
                diff--;
            }
        }else if(depthQ>depthP){
            int diff=depthQ-depthP;
            while(diff!=0){
                q=q->parent;
                diff--;
            }
        }

        // Now both at same depth
        while(p!=q){
            p=p->parent;
            q=q->parent;
        }

        return p;
    }
};