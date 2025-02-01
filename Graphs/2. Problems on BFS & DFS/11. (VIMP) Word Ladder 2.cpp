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


// Revision - 2

// Push paths - MLE
class Solution {
public:
    vector<vector<string> > bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string, vector<string> > &myMap){
        // push paths into the queue instead of current word
        // current word would be the last element in the vector

        queue<vector<string> > mq;
        unordered_set<string> isVisited;

        mq.push({beginWord});
        isVisited.insert(beginWord);
        
        vector<vector<string> > ans;

        bool stop=false;
        while(!mq.empty()){
            int size=mq.size();

            unordered_set<string> neighbours;
            for(int i=0;i<size;i++){
                vector<string> front=mq.front();
                mq.pop();

                if(front[front.size()-1]==endWord){
                    stop=true;
                    // Stop after this level is complete we only want shortest paths
                    ans.push_back(front);
                }

                // hot -> from here we can go to *ot , h*t and hi*
                // see from these states which words we can go to
                string currentWord = front[front.size()-1];
                for(int j=0;j<currentWord.length();j++){
                    string temp=currentWord;
                    temp[j]='*';

                    for(int k=0;k<myMap[temp].size();k++){
                        string nextWord=myMap[temp][k];

                        if(isVisited.find(nextWord)==isVisited.end()){
                            vector<string> nextPath = front;
                            nextPath.push_back(nextWord);
                            mq.push(nextPath);

                            /* Don't mark visited until this level complete since we want all possible shortest paths*/
                            /* another word could transform into same word and lead to end word*/
                            //isVisited.insert(nextWord);
                            neighbours.insert(nextWord); // mark as visited in next level
                        }
                    }
                }
            }

            for(auto it=neighbours.begin();it!=neighbours.end();it++){
                isVisited.insert(*it);
            }

            if(stop){
                break;
            }
        }

        return ans;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         int n=wordList.size();

       //  from hit we can change any one letter
       // *it , h*t, hi* are the options

       // from word dict h*t can be transformed into hot
       // similary *ot can be transformed into dot or lot

       // so we can keep a mapping of these 
       // *ot -> dot, lot 
       // for every word in wordList

       unordered_map<string, vector<string> > myMap;

       for(int i=0;i<wordList.size();i++){
        string str=wordList[i];
        for(int j=0;j<str.length();j++){
            // add a '*' at this position
            string temp=str;
            temp[j]='*';
            myMap[temp].push_back(str); 
        }
       } 

        //    for(auto it:myMap){
        //     cout<<it.first<<" --> ";
        //     for(int i=0;i<it.second.size();i++){
        //         cout<<it.second[i]<<" ";
        //     }
        //     cout<<endl;
        //    }

       return bfs(beginWord, endWord, wordList, myMap);
    }
};

// Optimized 

/*
Use BFS to find the shortest path
And then use DFS to find all the shortest path transformations

beginWord = hit
endWord = cog

let's say transformation length is 5

store words explored at each level
and then do DFS from end word to start word
and push only those words which we discovered at level-1

VIMP: 
include beginWord in myMap if not present since we need to reach beginWord now 
so from hot -> hit
h*t should contain hit as well otherwise we won't be able to reach

include beginWord in myMap if not present since we need to reach beginWord now 
Wrong for test case beginWord = 'a' endWord = 'c' wordList=['a','b','c'] if we add without checking
*/
class Solution {
public:
    // Don't need visited we have levelMap
    void dfs(string startVertex, 
             string endVertex, 
             unordered_map<string, int > &levelMap,
             unordered_map<string, vector<string> > &myMap,
             vector<string> path,
             vector<vector<string> > &ans){

                
        if(startVertex==endVertex){
            ans.push_back(path);
            return;
        }
        

        // from startVertex which words can we go to
        for(int i=0;i<startVertex.length();i++){
            string nextState=startVertex;
            nextState[i]='*';
            for(int j=0;j<myMap[nextState].size();j++){
                string nextWord=myMap[nextState][j];

                // see if one level down
                if(levelMap[nextWord]==levelMap[startVertex]-1){
                    // explore this path
                    path.push_back(nextWord);
                    dfs(nextWord, endVertex, levelMap, myMap, path, ans);
                    path.pop_back();
                }
            }
        }
    }
    // stores level for each string
    unordered_map<string,int> bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string, vector<string> > &myMap){
        queue<string> mq;
        unordered_set<string> isVisited;
        unordered_map<string,int> levelMap;

        mq.push(beginWord);
        isVisited.insert(beginWord);
        levelMap[beginWord]=1;

        int level=2;
        bool foundEndWord=false;
        while(!mq.empty()){
            int size=mq.size();
            for(int i=0;i<size;i++){
                string front=mq.front();
                mq.pop();

                if(front==endWord){
                    foundEndWord=true;
                    // not return here since multiple paths can lead to this at a particular level
                }

                // hot -> from here we can go to *ot , h*t and hi*
                // see from these states which words we can go to

                for(int j=0;j<front.length();j++){
                    string temp=front;
                    temp[j]='*';

                    for(int k=0;k<myMap[temp].size();k++){
                        string nextWord=myMap[temp][k];

                        if(isVisited.find(nextWord)==isVisited.end()){
                            mq.push(nextWord);
                            isVisited.insert(nextWord);
                            levelMap[nextWord]=level;
                        }
                    }
                }
            }
            level++;
            if(foundEndWord){
                break; // since we only want shortest path
            }
        }

        return levelMap;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string> > myMap;

        bool containsBeginWord=false;
        for(int i=0;i<wordList.size();i++){
            string str=wordList[i];
            if(str==beginWord){
                containsBeginWord=true;
            }
            for(int j=0;j<str.length();j++){
                // add a '*' at this position
                string temp=str;
                temp[j]='*';
                myMap[temp].push_back(str); 
            }
        } 

        if(!containsBeginWord){
            for(int i=0;i<beginWord.length();i++){
                    string temp=beginWord;
                    temp[i]='*';
                    myMap[temp].push_back(beginWord);
            }
        }
        

        unordered_map<string, int > levelMap = bfs(beginWord, endWord, wordList, myMap);

        // for(auto it:levelMap){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        // now do dfs from endWord to beginWord
        vector<vector<string> > ans;
        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, levelMap, myMap, path, ans);

        // reverse the paths
        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};