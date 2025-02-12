// https://leetcode.com/problems/merge-intervals/

/*
Sort intervals by their start time
Now (a,b) (c,d)

Given now that a<=c

so overlap only if c<=b ie. start time of 2nd interval before end time of previous
and after merging it would be
(a, max(b,d))
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int> > ans;

        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int a=ans.back()[0];
            int b=ans.back()[1];
            int c=intervals[i][0];
            int d=intervals[i][1];

            // overlap
            if(c<=b){
                ans.pop_back();
                ans.push_back({a, max(b,d)});
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};