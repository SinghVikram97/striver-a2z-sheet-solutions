// https://leetcode.com/problems/implement-trie-prefix-tree/description/
class TrieNode{
    vector<TrieNode*> alphabets{26, NULL};
    bool flag;

public:
    TrieNode(){
        flag=false;
    }

    bool containsKey(char ch){
        if(alphabets[ch-'a']!=NULL){
            return true;
        }else{
            return false;
        }
    }

    TrieNode* addKey(char ch){
        TrieNode *newNode = new TrieNode();
        this->alphabets[ch-'a']=newNode;
        return newNode;
    }
    
    TrieNode* getKey(char ch){
        return alphabets[ch-'a'];
    }

    void setFlag(){
        this->flag=true;
    }

    bool getFlag(){
        return this->flag;
    }
};
class Trie {
public:
    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int n=word.size();

        // start from root
        TrieNode *curNode = root;
        for(int i=0;i<n;i++){
            if(curNode->containsKey(word[i])){
                // move to the next node
                curNode = curNode->getKey(word[i]);
            }else{
                // create one
                TrieNode* addedWord = curNode->addKey(word[i]);
                // move to the next ie. for ex apple insert a now move to next
                curNode=addedWord;
            }
        }

        // in case of apple 
        // TrieNode will have in e's place a TrieNode whose flag will be set
        curNode->setFlag();

    }
    
    bool search(string word) {
        TrieNode *curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->containsKey(word[i])){
                curNode = curNode->getKey(word[i]);
            }else{
                return false;
            }
        }

        // check flag at the end maybe its middle of some other word
        if(curNode->getFlag()){
            return true;
        }else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode *curNode=root;
        for(int i=0;i<prefix.length();i++){
            if(curNode->containsKey(prefix[i])){
                curNode = curNode->getKey(prefix[i]);
            }else{
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */