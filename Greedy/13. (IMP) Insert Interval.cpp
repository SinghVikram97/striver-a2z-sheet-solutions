// https://leetcode.com/problems/insert-interval/description/

// Use merge interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int> > v;

        int n=intervals.size();
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }

        v.push_back({newInterval[0],newInterval[1]});

        sort(v.begin(),v.end());


        // (a,b)(c,d)
        // it is guaranteed that c>=a 
        // so for them to be overlapping c<=b

        vector<vector<int> > ans;
        ans.push_back({v[0].first,v[0].second});

        for(int i=1;i<v.size();i++){
            vector<int> last=ans.back();
            int a=last[0];
            int b=last[1];

            // overlap
            if(v[i].first<=b){
                ans.pop_back();
                ans.push_back({a,max(b,v[i].second)});
            }else{
                // just push
                ans.push_back({v[i].first,v[i].second});
            }
        }

        return ans;
    }
};