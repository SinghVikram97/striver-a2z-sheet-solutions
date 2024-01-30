// https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        // priority_queue of element,freq
        // for each group take out from the top
        // decrease it freq and push to temp array
        // select from next available elements

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->first,it->second});
        }

        int groups=n/groupSize;

        while(groups>0 && !pq.empty()){
            
            int N=groupSize;
            vector<pair<int,int> > temp; // store elements out for this group

            // pick N elements for group
            int prev=-1;
            while(N>0 && !pq.empty()){ 
                pair<int,int> topEle=pq.top();
                pq.pop();

                cout<<topEle.first<<endl;

                // push back to temp
                if(topEle.second-1>0){
                    temp.push_back({topEle.first,topEle.second-1});
                }

                // Check with previous
                if(prev!=-1){
                    if(topEle.first!=prev+1){
                        return false;
                    }else{
                        prev=topEle.first;
                    }
                }else{
                    prev=topEle.first;
                }
                N--;
            }

            if(N>0){
                return false; // no other option left in pq
            }

            // Add back elements to pq
            for(int i=0;i<temp.size();i++){
                pq.push({temp[i].first,temp[i].second});
            }
            groups--;
        }

        if(groups>0){
            return false;
        }

        return true;
    }
};