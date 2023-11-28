// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/*

, to separate numbers
# for null nodes


*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializeString="";

        if(!root){
            return serializeString;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);

        while(!myQueue.empty()){
            int size=myQueue.size();
            for(int i=0;i<size;i++){
                TreeNode* front = myQueue.front();
                myQueue.pop();

                if(front!=NULL){
                    serializeString+=to_string(front->val)+",";
                    myQueue.push(front->left);
                    myQueue.push(front->right);
                }else{
                    serializeString+="#,";
                }
            }
        }
        cout<<serializeString<<endl;
        return serializeString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }

        int index=0;
        string s="";
        while(data[index]!=','){
            s+=data[index];
            index++;
        }
        index++; // for ,

        queue<TreeNode*> myQueue;
        TreeNode* root = new TreeNode(stoi(s));
        myQueue.push(root);

        while(!myQueue.empty()){
            TreeNode* parent = myQueue.front();
            myQueue.pop();

            s="";
            while(data[index]!=','){
                s+=data[index];
                index++;
            }
            index++;

            if(s=="#"){
                parent->left=NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(s));
                parent->left=leftNode;
                myQueue.push(leftNode);
            }

            s="";
            while(data[index]!=','){
                s+=data[index];
                index++;
            }
            index++;

            if(s=="#"){
                parent->right=NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(s));
                parent->right=rightNode;
                myQueue.push(rightNode);
            }
        }
        return root;
    }
};