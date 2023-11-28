// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // distance, list of nodes
        unordered_map<int, vector<int> > mp;
        // val, dist
        queue<pair<TreeNode*,int> > mq;
        mq.push({root,0});

        int minDist=INT_MAX-5;
        int maxDist=INT_MIN+5;

        while(!mq.empty()) {
            int size=mq.size();
            unordered_map<int, vector<int> > tempMp;
            for(int i=0;i<size;i++){
                pair<TreeNode*,int> front = mq.front();
                mq.pop();

                TreeNode* actualNode = front.first;
                int dist=front.second;

                minDist=min(minDist,dist);
                maxDist=max(maxDist,dist);

                tempMp[dist].push_back(actualNode->val);

                if(actualNode->left!=NULL){
                    mq.push({actualNode->left,dist-1});
                }

                if(actualNode->right!=NULL){
                    mq.push({actualNode->right,dist+1});
                }
            }

            for(auto it=tempMp.begin();it!=tempMp.end();it++) {
                vector<int> temp = tempMp->second;
                sort(temp.begin(), temp.end());
                
                for(int i=0;i<temp.size();i++){
                    mp[it->first].push_back(temp[i]);
                }
            }
        }
        vector<vector<int> > ans;
        
        for(int i=minDist;i<=maxDist;i++){
            vector<int> temp = mp[i];
            ans.push_back(temp);
        }

        return ans;
    }
};

// Store both level and vd

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // [vertical distance, [level, list of nodes] ] = list of nodes at a particular level with given vd
        unordered_map<int, map<int, vector<int> > > mp;
    
        // (val, (dist, level))
        queue<pair<TreeNode*,pair<int,int > > > mq;
        mq.push({root,{0,0}});

        int minDist=INT_MAX-5;
        int maxDist=INT_MIN+5;
        
        while(!mq.empty()) {
            int size=mq.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*,pair<int,int> > front = mq.front();
                mq.pop();

                TreeNode* actualNode = front.first;
                int dist=front.second.first;
                int level=front.second.second;

                mp[dist][level].push_back(actualNode->val);

                minDist=min(minDist,dist);
                maxDist=max(maxDist,dist);


                if(actualNode->left!=NULL){
                    mq.push({actualNode->left,{dist-1,level+1}});
                }

                if(actualNode->right!=NULL){
                    mq.push({actualNode->right,{dist+1,level+1}});
                }
            }

            
        }
        vector<vector<int> > ans;
        
        for(int i=minDist;i<=maxDist;i++){
            // map because need to traverse level wise 
            map<int,vector<int> > mapLevelNode = mp[i];
            vector<int> dist;
            for(auto it=mapLevelNode.begin();it!=mapLevelNode.end();it++){
                // sort nodes at same level before adding
                vector<int> temp = it->second;
                sort(temp.begin(),temp.end());
                for(int j=0;j<temp.size();j++){
                    cout<<temp[j]<<endl;
                    dist.push_back(temp[j]);
                }
            }
            ans.push_back(dist);
        }

        return ans;
    }
};