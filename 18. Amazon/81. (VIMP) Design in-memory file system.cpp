// https://leetcode.com/problems/design-in-memory-file-system/description/

/*
In a TrieNode we need to store 2 things

First:
if path ending is a file
if path ending is a directory

and if path directory we need to return its direct children

for example directory /a/b/c 
inside which files d,e,f and more directories g,h,i and which contain more file

we only need to return d,e,f and g,h,i not what is inside ie. one level below

Second: keys equal to path
*/
class TrieNode {
    bool isDir;
    unordered_map<string, TrieNode*> mp;
    string content;

public:
    TrieNode() {
         isDir = true; 
         content = "";
    }

    TrieNode* addKey(string key) {
        TrieNode* newNode = new TrieNode();
        mp[key] = newNode;
        return mp[key];
    }

    TrieNode* getKey(string key) {
        return mp[key];
    }

    bool containsKey(string key){
        if(mp.find(key)==mp.end()){
            return false;
        }else{
            return true;
        }
    }

    bool isDirCheck(){
        return isDir;
    }

    void setFile(){
        isDir=false;
    }

    string getContent(){
        return content;
    }

    void setContent(string contentParameter){
        content = contentParameter;
    }

    vector<string> getAllKeys(){
        vector<string> keys;
        for(auto it:mp){
            keys.push_back(it.first);
        }
        return keys;
    }

};


class Trie{
    TrieNode *root;

public:
    Trie(){
        root = new TrieNode();
    }

    bool insertDir(string path){
        TrieNode *curNode = root;

        // start from 1 as first is /
        string temp="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode=curNode->getKey(temp);
                }else{
                    // default trienode is a directory so no need to setDir
                    curNode=curNode->addKey(temp); 
                }
                temp="";
            }
        }

        // for last /abc/ghf/dcf
        // dfc
        if(curNode->containsKey(temp)){
            curNode=curNode->getKey(temp);
        }else{
            curNode=curNode->addKey(temp);
        }

        // no need to mark dir by default dir
        return true;
    }

    bool insertFile(string path){
        TrieNode *curNode = root;

        // start from 1 as first is /
        string temp="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode=curNode->getKey(temp);
                }else{
                    // users will not attempt to retrieve file content or list a directory or 
                    // file that does not exist.
                    // no case of this happening
                }
                temp="";
            }
        }

        // for last /abc/ghf/dcf
        // last is file name, add file if doesn't exist
        if(curNode->containsKey(temp)){
            curNode=curNode->getKey(temp);
        }else{
            curNode=curNode->addKey(temp);
        }

        // mark as file
        curNode->setFile();

        return true;
    }

    void addContentToFile(string path, string content){
        TrieNode *curNode = root;

        // start from 1 as first is /
        string temp="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode=curNode->getKey(temp);
                }else{
                    // users will not attempt to retrieve file content or list a directory or 
                    // file that does not exist.
                    // no case of this happening
                }
                temp="";
            }
        }

        // for last /abc/ghf/dcf
        // last is file name

        // if file exists append content
        // otherwise add file
        if(curNode->containsKey(temp)){
            curNode=curNode->getKey(temp);
        }else{
            curNode=curNode->addKey(temp);
        }

        // mark as file
        curNode->setFile();
        curNode->setContent(curNode->getContent()+content);
    }

    string readContentFromFile(string path){
        TrieNode *curNode = root;

        // start from 1 as first is /
        string temp="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode=curNode->getKey(temp);
                }else{
                    // users will not attempt to retrieve file content or list a directory or 
                    // file that does not exist.
                    // no case of this happening
                }
                temp="";
            }
        }

        // for last /abc/ghf/dcf
        // last is file name
        if(curNode->containsKey(temp)){
            curNode=curNode->getKey(temp);
        }else{
            // file will exist
        }

        // return content
        return curNode->getContent();
    }

    vector<string> listDirectoryOrFile(string path){
        TrieNode *curNode = root;

        // start from 1 as first is /
        string temp="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/'){
                temp=temp+path[i];
            }else{
                if(curNode->containsKey(temp)){
                    curNode=curNode->getKey(temp);
                }else{
                    // user will always supply valid path
                }
                temp="";
            }
        }

        // for last /abc/ghf/dcf
        // dfc
        // store this
        string name = temp;
        if(curNode->containsKey(temp)){
            curNode=curNode->getKey(temp);
        }else{
            // user will always supply valid path
        }

        // check if file or directory
        if(curNode->isDirCheck()){
            // need to get all keys this node contains
            vector<string> list=curNode->getAllKeys();
            sort(list.begin(), list.end());
            return list;
            
        }else{
            // return file name
            return {name};
        }
    }
};
class FileSystem {
    Trie* trie;
public:
    FileSystem() {
        trie = new Trie();
    }

    vector<string> ls(string path) {
        return trie->listDirectoryOrFile(path);
    }

    void mkdir(string path) {
        trie->insertDir(path);
    }

    void addContentToFile(string filePath, string content) {
        trie->addContentToFile(filePath, content);
    }

    string readContentFromFile(string filePath) {
        return trie->readContentFromFile(filePath);
    }
};

// TC: 
/*
mkdir, addContent, readContent	O(L) where L is the length of path (or # of directories)
ls	O(L + K log K), where K is number of children
*/