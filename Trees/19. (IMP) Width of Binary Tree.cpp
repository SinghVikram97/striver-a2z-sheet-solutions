// https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        // Node, index
        // left -> 2*index
        // right -> 2*index+1
        queue<pair<TreeNode*, long long int> > myQueue;
        myQueue.push({root,1});
        long long int maxWidth = -1;

        while(!myQueue.empty()){
            int size = myQueue.size();
            long long int mini = -1;
            long long int width = -1;
            for(int i=0;i<size;i++){
                pair<TreeNode*, long long int> frontNodePair = myQueue.front();
                myQueue.pop();

                TreeNode* frontNode = frontNodePair.first;
                long long int indexOfNode = frontNodePair.second;

                if(mini==-1){
                    mini=indexOfNode;
                    width=0;
                }
                else{
                    width = indexOfNode-mini;
                }

                maxWidth=max(maxWidth, width);

                // since only width matters we can substract mini
                // for ex. in next level if leftmost node has width 4 and righmost node has index 7 
                // we can substract 2(minimum index at previous level) from them 7-4=3=(7-2)-(4-2)

                long long int leftIndex = (long long int)(2*indexOfNode)-mini;
                long long int rightIndex = ((long long int)(2*indexOfNode)+1)-mini;

                if(frontNode->left){
                    myQueue.push({frontNode->left, leftIndex});
                }

                if(frontNode->right){
                    myQueue.push({frontNode->right, rightIndex});
                }
            }
        }
        return maxWidth+1;
    }
};