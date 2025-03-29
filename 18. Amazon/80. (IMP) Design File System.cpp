// https://leetcode.com/problems/design-file-system/description/

// TC: O(N) length of path to construct the parent path
class FileSystem {
public:
    unordered_map<string, int> mp;
    FileSystem() {
    }

    bool createPath(string path, int value) {
        // Check if parent path exists or path already exists

        // 1. Path exists
        if(mp.find(path)!=mp.end()){
            return false;
        }

        // 2. Parent path doesn't exist
        string parentPath = getParentPath(path);

        if(parentPath!="/" && get(parentPath)==-1){
            return false;
        }

        // 3. Create path
        mp[path]=value;
        return true;
    }

    int get(string path) {
        auto it = mp.find(path);
        if (it != mp.end()) {
            return mp[path];
        } else {
            return -1;
        }
    }

    string getParentPath(string path){
        /*
            / -> invalid
            /abc -> root path, lastSlash at index 0 (return parent as / )
            /abc/def -> lastSlash index > 0 ( return parent as /abc )
        */
        int n=path.length();
        int lastSlash = -1;

        for(int i=n-1;i>=0;i--){
            if(path[i]=='/'){
                lastSlash=i;
                break;
            }
        }

        if(lastSlash==-1){
            return ""; // invalid path
        }

        if(lastSlash==0 && path.length()<2){
            return ""; // invalid path
        }

        if(lastSlash==0){
            return "/";
        }

        string parentPath="";
        for(int i=0;i<lastSlash;i++){
            parentPath = parentPath + path[i];
        }

        return parentPath;
    }
};

// Using Trie

// Root of the Trie is "/"
// Then we have nodes /abcd /abc (With string after slash as children)
// Then for /abc/def we would have a child for /abc with /def and mark it as ending node

// Less space
// TC: O(T) length of trie
class TrieNode{
    unordered_map<string, TrieNode*> mp;
    int flag; // -1 indicates no path ends at this node

public:
    TrieNode(){
        flag=-1;
    }

    bool containsKey(string key){
        if(mp.find(key)!=mp.end()){
            return true;
        }else{
            return false;
        }
    }

    TrieNode* addKey(string key){
        TrieNode* newNode = new TrieNode();
        mp[key]=newNode;
        return newNode;
    }

    TrieNode* getKey(string key){
        return mp[key];
    }

    void setFlag(int value){
        flag=value;
    }

    int getFlag(){
        return flag;
    }
};

class Trie{
    TrieNode *root;

public:
    Trie(){
        root = new TrieNode();
    }

    /*
        /acb
        /acd/def
        /acd/def/ghi

        / -> invalid
        "" -> invalid
    */
    bool insert(string path, int value){
        int n=path.length();

        string temp="";
        TrieNode *curNode = root;
        // start from 1 since / at 0

        for(int i=1;i<n;i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                // check if this folder exists
                if(curNode -> containsKey(temp)){
                    curNode = curNode->getKey(temp);
                }else{
                    // create one -> but here don't create if parent doesn't exist

                    // TrieNode *addedKey = curNode->addKey(temp);
                    // curNode = addedKey;
                    return false;
                }
                // reset temp
                temp="";
            }
        }

        // at last for the last string
        // example /abc/def/ghi
        // for ghi

        if(curNode->containsKey(temp)){
            curNode = curNode->getKey(temp);
        }else{
            TrieNode *addedKey = curNode->addKey(temp);
            curNode = addedKey;
        }

        // check flag if already exists
        if(curNode->getFlag()!=-1){
            return false; // already exists
        }

        // set flag for last node
        curNode->setFlag(value);
        // can exist for another path but without end for example: /abc/def/ghi
        // and we are inserting /abc/def
        return true;
    } 

    int search(string path){
        int n=path.length();
        if(n==0){
            return -1;
        }

        if(path=="/" || path==""){
            return -1;
        }

        TrieNode *curNode = root;

        string temp="";
        for(int i=1;i<n;i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode = curNode->getKey(temp);
                    temp="";
                }else{
                    return -1;
                }
            }
        }

        // last path after /
        if(curNode->containsKey(temp)){
            curNode = curNode->getKey(temp);
        }else{
            return -1;
        }

        // check if any path ends here
        if(curNode->getFlag()){
            return curNode->getFlag();
        }else{
            return -1;
        }
    }
};
class FileSystem {
public:
    Trie *trie;
    FileSystem() {
        trie = new Trie();
    }
    
    bool createPath(string path, int value) {
        return trie->insert(path, value);
    }
    
    int get(string path) {
        return trie->search(path);
    }
};