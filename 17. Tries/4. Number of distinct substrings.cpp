// https://www.naukri.com/code360/problems/count-distinct-substrings_985292

// Brute Force 
// TC -> O(N^3) O(N) to insert string into set
#include<bits/stdc++.h>
int countDistinctSubstrings(string &s)
{
    unordered_set<string> ms;

    int n=s.length();

    for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j<n;j++){
            temp=temp+s[j];
            ms.insert(temp);
        }
    }
    return ms.size()+1;
}

// Basically count number of words in Trie and don't storing endingCount
// O(N^2)
#include<bits/stdc++.h>
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

    int numWords(){
        return helper(root);
    }

    int helper(TrieNode *root){
        if(root==NULL){
            return 0;
        }

        int count=0;

        for(int i=0;i<26;i++){
            char ch=i+'a';

            if(root->containsKey(ch)){
                TrieNode *nextNode = root->getKey(ch);

                count = count + helper(nextNode);
            }
            
        }

        if(root->getFlag()){
            // some word ends at this too
            count=count+1;
        }
        return count;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie *trie = new Trie();

    // Store all prefixes in Trie
    for(int i=0;i<s.length();i++){
        string temp="";
        for(int j=i;j<s.length();j++){
            temp=temp+s[j];
            trie->insert(temp);
        }
    }

    // Get words in trie + 1 for empty string
    return trie->numWords()+1;
}