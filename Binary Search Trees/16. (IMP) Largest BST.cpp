// https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103


// Check if left and right subtree bst if yes then check 
// if root > largest element in left subtree and root < smallest element in right subtree
// then subtree rooted at root also a bst

class NodeInfo{
    public:
        NodeInfo(bool isBST,int maxEle,int minEle,int size){
            this->isBST=isBST;
            this->maxEle=maxEle;
            this->minEle=minEle;
            this->size=size;
        }
        bool isBST;
        int maxEle;
        int minEle;
        int size;
};

NodeInfo helper(TreeNode *root, int &maxSize){
    if(root==NULL){
        return NodeInfo(true, INT_MIN,INT_MAX,0);
    }

    NodeInfo leftSubtree=helper(root->left,maxSize);
    NodeInfo rightSubtree=helper(root->right,maxSize);

    int maxEle = max({root->data,leftSubtree.maxEle,rightSubtree.maxEle});
    int minEle = min({root->data,leftSubtree.minEle,rightSubtree.minEle});
    int size = 1+leftSubtree.size+rightSubtree.size;
    bool isBST=false;

    if(leftSubtree.isBST && rightSubtree.isBST && root->data>leftSubtree.maxEle && root->data<rightSubtree.minEle){
        isBST=true;
        maxSize=max(size,maxSize);
    }

    return NodeInfo(isBST,maxEle,minEle,size);
}

int largestBST(TreeNode * root){
    int maxSize=-1;
    helper(root,maxSize).size;
    return maxSize;
}

// Naive Approach
// Find inorder 
// Then find largest sorted sequence
/*

    10
   / \
  2   14
 / \  |
1  5  20

The inorder-traversal is 1 2 5 10 20 14. 
Don't select the 20. 
I think this can be accomplished by making sure you dismiss elements as long as their selection stops
making sense. 
For example, when you reach 14, dismiss the 20.

Desired output 3 
Our output 5


*/

