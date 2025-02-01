// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

/*
We use offline queries

Online queries -> generally we have a function that we run for each query item and append our ans to the list of ans

Offline queries ->
Here we change the order in which we process the queries we sort it by Mi since we want xor with numbers less then Mi
Then we also sort nums[i] and then add numbers to trie only when a number is <= Mi
This way our trie only has numbers less than Mi at any point and the question becomes same as previous question
*/
class TrieNode{
    vector<TrieNode*> bits{2, NULL}; // 0 and 1
    // don't need flag since we always traverse all 32 bits

public:
    TrieNode(){
        
    }

    bool containsKey(int bit){
        if(bits[bit]!=NULL){
            return true;
        }else{
            return false;
        }
    }

    TrieNode* addKey(int bit){
        TrieNode *newNode = new TrieNode();
        this->bits[bit]=newNode;
        return newNode;
    }
    
    TrieNode* getKey(int bit){
        return bits[bit];
    }
};
class Trie {
public:
    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }
    
    void insert(int num) {
        TrieNode *curNode = root;

        // traverse all 32 bits
        for(int i=31;i>=0;i--){
            // i 31 means right shift 31 times to get the 32nd bit
            int bit = (num>>i) & 1; 

            if(curNode->containsKey(bit)){
                curNode = curNode->getKey(bit);
            }else{
                curNode = curNode->addKey(bit);
            }
        }
    }

    int getMax(int x){
        int ans = 0; // intially all 32 bits as 0
        TrieNode *curNode = root;

        // traverse all 32 bits
        for(int i=31;i>=0;i--){
            int xBit = (x>>i) & 1;

            int flippedBit = 1-xBit;

            // We want opposite/flipped bit
            if(curNode->containsKey(flippedBit)){
                // if it does we set this bit as 1 in our ans
                ans = ans | (1<<i); // take OR with bit set at ith bit
                curNode = curNode -> getKey(flippedBit);
            }else{
                // else take original bit ie. other option
                ans = ans | (0 << i); // can skip this since we have set all bits as 0 initially
                curNode = curNode -> getKey(xBit);
            }
        }

        return ans;
    }
    
    
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie *trie = new Trie();

        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i); // push index
        }

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });

        for(int i=0;i<queries.size();i++){
            cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<queries[i][2]<<endl;
        }


        // sorted queries based on mi
        int index=0;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            while(index<nums.size() && nums[index]<=queries[i][1]){
                trie->insert(nums[index]);
                index++;
            }
            if(index==0){
                // this means trie empty
                ans[queries[i][2]]=-1;
            }else{
                ans[queries[i][2]]=trie->getMax(queries[i][0]);
            }
        }
        return ans;

    }
};