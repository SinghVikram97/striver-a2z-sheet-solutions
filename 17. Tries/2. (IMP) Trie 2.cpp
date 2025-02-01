// https://www.naukri.com/code360/problems/implement-trie_1387095
#include <bits/stdc++.h> 
class TrieNode{
    vector<TrieNode*> alphabets{26, NULL};
    int count;
    int endsWithCount;

public:
    TrieNode(){
        count=0;
        endsWithCount=0;
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

    void incrementCount(){
        this->count=this->count+1;
    }

    void decrementCount(){
        this->count=this->count-1;
    }

    int getCount(){
        return this->count;
    }

    void incrementEndsWithCount(){
        this->endsWithCount+=1;
    }

    void decrementEndsWithCount(){
        this->endsWithCount-=1;
    }

    int getEndsWithCount(){
        return this->endsWithCount;
    }
};
class Trie{
    TrieNode *root;

    public:
    Trie(){
        root= new TrieNode();
    }

    void insert(string &word){
        int n=word.size();

        // start from root
        TrieNode *curNode = root;
        for(int i=0;i<n;i++){
            if(curNode->containsKey(word[i])){
                // move to the next node
                curNode = curNode->getKey(word[i]);
                // for example apple
                // here for root in a's place we have a TrieNode
                // We get that TrieNode and increment its count
                curNode->incrementCount();
            }else{
                // create one
                TrieNode* addedWord = curNode->addKey(word[i]);
                // increment count for example apple
                // root will have in a's place a TrieNode whose count will be 1
                addedWord->incrementCount();
                // move to the next ie. for ex apple insert a now move to next
                curNode=addedWord;
            }
        }

        
        curNode->incrementEndsWithCount();

    }

    int countWordsEqualTo(string &word){
        TrieNode *curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->containsKey(word[i])){
                curNode = curNode->getKey(word[i]);
            }else{
                return false;
            }
        }

        return curNode->getEndsWithCount();
    }

    int countWordsStartingWith(string &word){
        TrieNode *curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->containsKey(word[i])){
                curNode = curNode->getKey(word[i]);
            }else{
                return false;
            }
        }

        // return count
        return curNode->getCount();
    }

    void erase(string &word){
       TrieNode *curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->containsKey(word[i])){
                curNode = curNode->getKey(word[i]);
                // decrease its count
                curNode->decrementCount();
            }else{
                // guaranteed word is present
            }
        }

        curNode->decrementEndsWithCount();
    }
};
