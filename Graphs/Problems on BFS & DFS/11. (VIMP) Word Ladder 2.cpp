// https://leetcode.com/problems/word-ladder-ii/


// TLE - Push paths into queue with BFS

class Solution {
public:

    vector<vector<string> > bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string,vector<string> > myMap){
        // Instead of words we will have paths in queue
        queue<vector<string> > mq;
        unordered_map<string,bool> visited;

        mq.push({beginWord});
        visited[beginWord]=true;

        vector<vector<string> > ans;

        while(!mq.empty()) {

            int size = mq.size();

            // Level start
            unordered_set<string> neighbours;
            bool shouldStop = false;
            for(int i=0;i<size;i++) {
                vector<string> path = mq.front();
                mq.pop();

                // Transform / find neighbours of last element of vector 
                string front = path[path.size()-1];

                if(front==endWord) {
                    ans.push_back(path);
                    shouldStop = true; // Stop after this level is complete we only want shortest paths
                }

                for(int j=0;j<front.length();j++) {
                    string nextState = front;
                    nextState[j]='*';

                    for(int k=0;k<myMap[nextState].size();k++){
                        if(!visited[myMap[nextState][k]]){
                            vector<string> nextPath = path;
                            nextPath.push_back(myMap[nextState][k]);
                            mq.push(nextPath);
                            /* Don't mark visited until this level complete since we want all possible shortest paths*/
                            /* another word could transform into same word and lead to end word*/
                            neighbours.insert(myMap[nextState][k]);
                        }
                    }
                }
            }
            
            // Mark every neighbour visited now 
            for(auto it=neighbours.begin();it!=neighbours.end();it++){
                visited[(*it)]=true;
            }

            if(shouldStop){
                return ans;
            }
        }
        
        return ans;
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string> > myMap;

        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].length();j++){
                string nextState = wordList[i];
                nextState[j] = '*';
                myMap[nextState].push_back(wordList[i]);
            }
        }

        return bfs(beginWord,endWord,wordList,myMap);
    }
};


// BFS - to find shortest path + DFS- to find paths

// Step1 -> Find shortest path + Map levels to words
// Step2 -> Do DFS from endWord to startWord and check using levels to form path


class Solution {
public:

    // step 2
    void dfs(string startVertex,
             string endVertex, 
             unordered_map<string,vector<string> > &myMap, 
             unordered_map<string,int> &levelMap,
             vector<string> path,
             vector<vector<string> > &ans){

       if(startVertex == endVertex){
         ans.push_back(path);
         return;
       } 

       for(int i=0;i<startVertex.length();i++){
         string nextState = startVertex;
         nextState[i]='*';

         for(int j=0;j<myMap[nextState].size();j++){
            if(levelMap[myMap[nextState][j]]==levelMap[startVertex]-1){
                path.push_back(myMap[nextState][j]);
                dfs(myMap[nextState][j], endVertex, myMap, levelMap, path, ans);
                path.pop_back();
            }
         } 
       }


    }

    // Step 1
    unordered_map<string,int> bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string,vector<string> > myMap){
        queue<string> mq;
        unordered_map<string,bool> visited;
        unordered_map<string,int> levelMap;

        mq.push(beginWord);
        visited[beginWord]=true;
        levelMap[beginWord]=1;

        int level = 2;
        while(!mq.empty()){
            int size = mq.size();
            for(int i=0;i<size;i++){
                string front = mq.front();
                mq.pop();

                for(int j=0;j<front.length();j++){
                    string nextState = front;
                    nextState[j]='*';

                    for(int k=0;k<myMap[nextState].size();k++){
                        if(!visited[myMap[nextState][k]]){
                            mq.push(myMap[nextState][k]);
                            visited[myMap[nextState][k]]=true;
                            levelMap[myMap[nextState][k]]=level;
                        }
                    }
                }
            }

            level++;
        }

        return levelMap;
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string> > myMap;

        bool containsBeginWord=false;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord){
                containsBeginWord=true;
            }
            for(int j=0;j<wordList[i].length();j++){
                string nextState = wordList[i];
                nextState[j] = '*';
                myMap[nextState].push_back(wordList[i]);
            }
        }


        unordered_map<string,int> levelMap = bfs(beginWord,endWord,wordList,myMap);

        // include beginWord in myMap if not present since we need to reach beginWord now 
        // Wrong for test case beginWord = 'a' endWord = 'c' wordList=['a','b','c'] if we add without checking
        if(!containsBeginWord){
            for(int i=0;i<beginWord.length();i++){
                string nextState = beginWord;
                nextState[i]='*';
                myMap[nextState].push_back(beginWord);
            }
        }

        
        // Do dfs from endWord
        // Don't need visited since 2 words can lead to same ancestor
        // ex. dot and lot will lead to hot
        // we are already checking levels so we won't visit backwards in a infinite loop
        vector<vector<string> > ans;
        vector<string> path;
        path.push_back(endWord);

        // start from end
        dfs(endWord, beginWord,myMap, levelMap, path, ans);

        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;

    }
};