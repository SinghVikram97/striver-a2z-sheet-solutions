// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:

    int bfs(string beginWord, string endWord, vector<string> &wordList, unordered_map<string,vector<string> > myMap){
        queue<string> mq;
        unordered_map<string,bool> visited;

        mq.push(beginWord);
        visited[beginWord]=true;

        int count=1;

        while(!mq.empty()){
            int size = mq.size();

            for(int i=0;i<size;i++){
                string front = mq.front();
                if(front==endWord){
                    return count;
                }
                mq.pop();

                for(int j=0;j<front.length();j++){
                    string nextState = front;
                    nextState[j]='*';

                    // traverse myMap, for ex for hot, *ot -> hot, dot, lot,,,, add dot and lot as neighbours

                    for(int k=0;k<myMap[nextState].size();k++){
                        // if not visited
                        if(!visited[myMap[nextState][k]]){
                            // Add to queue
                            mq.push(myMap[nextState][k]);
                            visited[myMap[nextState][k]]=true;
                        }
                    }
                }
            }

            count++;
        }
        return 0;
    }



    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Map of possible states to word
        // For ex. *ot---->hot dot lot 
        // for hot check its states ie. *ot, h*t, ho*
        // We can move from hot to words contained in map of above states
        unordered_map<string,vector<string> > myMap;

        // Generate possible states from each word
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].length();j++){
                string nextState = wordList[i];
                nextState[j]='*';
                myMap[nextState].push_back(wordList[i]);
            }
        }


        // for(auto it=myMap.begin();it!=myMap.end();it++){
        //     cout<<it->first<<"---->";
        //     for(int i=0;i<it->second.size();i++){
        //         cout<<it->second[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return 0;

        // start bfs and find shortest distance b/w begin word and end word
        return bfs(beginWord, endWord, wordList, myMap);
    }
};


// Another approach is just generate children of hot by trying to change every character from a-z and check if its in wordList
// ie. aot, bot, cot....., hat,hbt.........., hoa,hob
class Solution {
public:
    vector<string> generateChildren(string s,unordered_set<string> &wordsAllowed){

      // Can change a single alphabet 
      vector<string> ans;
      for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++){
          string temp=s;
          char ch=j+'a';
          if(ch!=temp[i]){
            temp[i]=ch;
            if(wordsAllowed.find(temp)!=wordsAllowed.end()){
              ans.push_back(temp);
            }
          }
        }
      }
      return ans;
    }
    int bfs(string beginWord,string endWord,vector<string> &wordList){
      
      unordered_set<string> wordsAllowed(wordList.begin(),wordList.end());
      unordered_set<string> isVisited;

      queue<string> myQueue;
      myQueue.push(beginWord);
      isVisited.insert(beginWord);
      int steps=1;
      while(!myQueue.empty()){

        int size=myQueue.size();
      
        for(int i=0;i<size;i++){

          string frontElement=myQueue.front();
          myQueue.pop();

          if(frontElement==endWord){
            return steps;
          }
          
          // Push valid chilren of frontElement into myQueue 
          vector<string> children=generateChildren(frontElement,wordsAllowed);

          for(int j=0;j<children.size();j++){
            if(isVisited.find(children[j])==isVisited.end()){
              myQueue.push(children[j]);
              isVisited.insert(children[j]);
            }
          }
          
        }

        steps++;
      }
      return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord,endWord,wordList);
    }
};