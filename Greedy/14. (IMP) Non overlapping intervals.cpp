// https://leetcode.com/problems/non-overlapping-intervals/description/
// [[1,2],[2,3],[3,4],[1,3]] -> remove [1,3] 
// sort -> [1,2][1,3][2,3][3,4] -> (1,2) and (1,3) overlap remove (1,3)

// how to decide which one to remove
// 1st can also be removed for ex.
// (1,6)(1,2)(4,5) -> remove (1,6) would be min removal

// Greedy? -> sort by end times instead

// (1,2)(4,5)(1,6)
// (a,b)(c,d)  b will be <=d so c<b will be overlap (1,2)(2,3) ie equal not considered overlap

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int> > v;

        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }

        // sort by end times
        sort(v.begin(),v.end(),[](const auto &x, const auto &y){
            if(x.second<y.second){
                return true;
            }
            else if(x.second==y.second){
                return x.first<y.first;
            }else{
                return false;
            }
        });

        int prev=v[0].second;
        int ans=0;

        for(int i=1;i<intervals.size();i++){
            int c=v[i].first;
            int b=prev;

            if(c<b){
                // overlap
                ans++;
            }else{
                // no overlap update prev
                prev=v[i].second;
            }
        }

        return ans;
    }
};

// Update
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1){
            return 0;
        }

        // sort by end times
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            return x[1]<y[1];
        });

        int count=0;
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevEnd){
                // overlap
                // remove
                count++;
            }else{
                // no overlap
                // update prevEnd
                prevEnd=intervals[i][1];
            }
        }

        return count;
    }
};