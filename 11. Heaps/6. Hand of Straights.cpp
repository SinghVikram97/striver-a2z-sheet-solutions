// https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();

        if(n%groupSize!=0){
            return false;
        }

        if(groupSize>n){
            return false;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        // value, freq
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        for(auto it:mp){
            pq.push({it.first, it.second});
        }

        while(!pq.empty()){
            vector<pair<int,int> > addBack;

            int N=groupSize;
            int prevEle=-1;

            // Try to make a group
            while(N!=0 && !pq.empty()){
                pair<int,int> topEle=pq.top();
                pq.pop();

                if(prevEle!=-1 && topEle.first!=prevEle+1){
                    return false;
                }

                prevEle=topEle.first;
                addBack.push_back({topEle.first, topEle.second-1});
                N--;
            }

            if(N!=0){
                return false;
            }

            for(int i=0;i<addBack.size();i++){
                if(addBack[i].second>0){
                    pq.push({addBack[i].first, addBack[i].second});
                }
            }
        }
        return true;
    }
};