// https://www.naukri.com/code360/problems/complete-string_2687860

// Brute Force
// TC: O(N^2)
#include <bits/stdc++.h> 
string completeString(int n, vector<string> &a){
    unordered_set<string> ms;

    for(int i=0;i<n;i++){
        ms.insert(a[i]);
    }

    string ans="";
    for(int i=0;i<n;i++){
        string temp="";
        bool allPresent=true;
        for(int j=0;j<a[i].length();j++){
            temp=temp+a[i][j];

            if(ms.find(temp)==ms.end()){
                allPresent=false;
                break;
            }
        }

        if(allPresent){
            if(a[i].length()>ans.length()){
                ans=a[i];
            }else if(a[i].length()==ans.length()){
                ans=min(ans, a[i]);
            }
        }
    }
    return ans==""?"None":ans;
}

// Using Trie
/*
First we build a Trie out of all strings in the array
Now we want longest string whose all prefixes are in Trie
So we do a DFS on trie and go downwards and at each node till ending flag is true ie. every prefix present

TC: O(Sum of length of all words in array)
*/
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

    string findLongestString(){
        TrieNode *curNode = root;
        return helper(root);
    }

    string helper(TrieNode *root){
        if(root==NULL){
            return "";
        }

        string ans="";

        for(int i=0;i<26;i++){
            char ch='a'+i;
            if(root->containsKey(ch)){
                TrieNode *next=root->getKey(ch);
                if(next->getFlag()){
                    string tempAns=helper(next);
                    
                    if(tempAns.length()+1>ans.length()){
                        ans=ch+tempAns;
                    }else if(tempAns.length()+1==ans.length()){
                        tempAns=ch+tempAns;
                        ans=min(ans,tempAns);
                    }
                    
                }else{
                    continue;
                }
            }
        }
        return ans;
    }
};

string completeString(int n, vector<string> &a){
    Trie *trie = new Trie();

    for(int i=0;i<n;i++){
        trie->insert(a[i]);
    }

    // Do DFS on Trie
    string ans=trie->findLongestString();
    if(ans==""){
        return "None";
    }else{
        return ans;
    }
}