// https://leetcode.com/problems/design-twitter/description/

// Brute Force

/*

TC:

1. postTweet -> O(logn) -> n tweets by user
2. getNewsFeed -> O(f⋅k+f⋅logk+plogp) where f number of followers, k number of tweets per follower
   p -> number of tweets collected from all users+user itself
3. follow -> O(n), where n followers size , to check for duplicate requests
4. unfollow -> O(n), where n followers size, to search for that followee id
*/

class Twitter {
public:
    // tweets by a user -> counter, tweetId
    unordered_map<int, priority_queue<pair<int,int > > > tweetMap;
    // user -> followers
    unordered_map<int, vector<int> > followerMap; 
    int counter=10; // dummy for timestamp, it keeps increasing helps sort tweets 
    // if counter more tweet more recent
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        counter++;
        tweetMap[userId].push({counter, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        return generateFeed(userId);
    }
    
    void follow(int followerId, int followeeId) {
        // check for duplicate follow requests
        for(int i=0;i<followerMap[followerId].size();i++){
            if(followerMap[followerId][i]==followeeId){
                return;
            }
        }
        followerMap[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0;i<followerMap[followerId].size();i++){
            if(followerMap[followerId][i]==followeeId){
                followerMap[followerId][i]=-1;
            }
        }
    }

    vector<int> generateFeed(int userId){
        // go through followers
        vector<int> followingList=followerMap[userId];

        vector<pair<int,int> > ans;

        for(int i=0;i<followingList.size();i++){

            if(followingList[i]!=-1){
                int followingId=followingList[i];

                // put 10 tweets of this user into ans
                priority_queue<pair<int,int> > tempPq=tweetMap[followingId];

                int count=0;

                while(count<10 && !tempPq.empty()){
                    pair<int,int> topEle=tempPq.top();
                    tempPq.pop();

                    ans.push_back(topEle);
                    count++;
                }
            }
        }

        // put 10 tweets of itself into ans
        priority_queue<pair<int,int> > tempPq=tweetMap[userId];
        int count=0;
        while(count<10 && !tempPq.empty()){
            pair<int,int> topEle=tempPq.top();
            tempPq.pop();
            cout<<topEle.first<<" "<<topEle.second<<endl;
            ans.push_back(topEle);
            count++;
        }

        // sort ans in descending order
        sort(ans.begin(),ans.end(), greater<pair<int,int> >());

        // take 1st 10 elements
        vector<int> tweetIdAns;
        int ansSize=ans.size();
        for(int i=0;i<min(10, ansSize);i++){
            tweetIdAns.push_back(ans[i].second);
        }

        return tweetIdAns;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


// Optimized
// Use set to store follower list to avoid duplicate following check
// Remove from set if unfollow -> O(1)
class Twitter {
public:
    // tweets by a user -> timestamp, tweetId
    unordered_map<int, priority_queue<pair<int,int > > > tweetMap;
    // user -> followers
    unordered_map<int, unordered_set<int> > followerMap; 
    int counter=10;
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        counter++;
        tweetMap[userId].push({counter, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        return generateFeed(userId);
    }
    
    void follow(int followerId, int followeeId) {
       followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }

    vector<int> generateFeed(int userId){
        // go through followers
        vector<pair<int,int> > ans;

        for(auto it=followerMap[userId].begin();it!=followerMap[userId].end();it++){
            // put 10 tweets of this user into ans
            priority_queue<pair<int,int> > tempPq=tweetMap[*it];

            int count=0;

            while(count<10 && !tempPq.empty()){
                pair<int,int> topEle=tempPq.top();
                tempPq.pop();

                ans.push_back(topEle);
                count++;
            }
        }

        // put 10 tweets of itself into ans
        priority_queue<pair<int,int> > tempPq=tweetMap[userId];
        int count=0;
        while(count<10 && !tempPq.empty()){
            pair<int,int> topEle=tempPq.top();
            tempPq.pop();
            cout<<topEle.first<<" "<<topEle.second<<endl;
            ans.push_back(topEle);
            count++;
        }

        // sort ans in descending order
        sort(ans.begin(),ans.end(), greater<pair<int,int> >());

        // take 1st 10 elements
        vector<int> tweetIdAns;
        int ansSize=ans.size();
        for(int i=0;i<min(10, ansSize);i++){
            tweetIdAns.push_back(ans[i].second);
        }

        return tweetIdAns;
    }
};



// Don't need to use priority queue
// Store tweets by a user in a vector one after another
// Take last 10 tweets by each user in following list
// You can use merge k sorted list logic or do simple sort algo to get the tweet list
class Twitter {
public:
    // tweets by a user -> timestamp, tweetId
    unordered_map<int, vector<pair<int,int> > > tweetMap;
    // user -> followers
    unordered_map<int, unordered_set<int> > followerMap; 
    int timestamp=10;
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweetMap[userId].push_back({timestamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        return generateFeed(userId);
    }
    
    void follow(int followerId, int followeeId) {
       followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }

    vector<int> generateFeed(int userId){
        // go through followers
        // take 10 tweets from each follower start from last
        vector<pair<int,int > > ans;

        for(auto it=followerMap[userId].begin();it!=followerMap[userId].end();it++){
            vector<pair<int,int > > tweetList=tweetMap[*it];

            int count=0;
            int index=tweetList.size()-1;
            while(count<10 && index>=0){
                ans.push_back(tweetList[index]);
                count++;
                index--;
            }
        }

        // put own tweets into ans
        vector<pair<int,int > > tweetList=tweetMap[userId];

        int count=0;
        int index=tweetList.size()-1;
        while(count<10 && index>=0){
            ans.push_back(tweetList[index]);
            count++;
            index--;
        }

        // sort ans in descending order
        sort(ans.begin(),ans.end(), greater<pair<int,int> >());

        // take 1st 10 elements
        vector<int> tweetIdAns;
        int ansSize=ans.size();
        for(int i=0;i<min(10, ansSize);i++){
            tweetIdAns.push_back(ans[i].second);
        }

        return tweetIdAns;
    }
};
