// https://www.codingninjas.com/studio/problems/merge-two-bsts_920474
void inOrder(TreeNode *root, vector<int> &ans){

    if(root==NULL){
        return;
    }

    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> inOrder1;
    inOrder(root1,inOrder1);

    vector<int> inOrder2;
    inOrder(root2,inOrder2);

    vector<int> finalAns;

    int i=0,j=0;
    while(i<inOrder1.size() && j<inOrder2.size()){
        if(inOrder1[i]<=inOrder2[j]){
            finalAns.push_back(inOrder1[i]);
            i++;
        }
        else{
            finalAns.push_back(inOrder2[j]);
            j++;
        }
    }

    while(i<inOrder1.size()){
        finalAns.push_back(inOrder1[i]);
        i++;
    }

    while(j<inOrder2.size()){
        finalAns.push_back(inOrder2[j]);
        j++;
    }
    return finalAns;
}