// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int> > pq;

        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }

        int i=k;
        vector<int> ans;
        while(i){
            pair<int,int> topEle=pq.top();
            ans.push_back(topEle.second);
            pq.pop();
            i--;
        }
        return ans;
    }
};