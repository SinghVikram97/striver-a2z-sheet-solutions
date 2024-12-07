// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        if(n<=1){
            return intervals;
        }

        // sort by start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int> > mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        int index=1;

        while(index<n){
            int lastEnd=mergedIntervals.back()[1];

            int curStart=intervals[index][0];
            int curEnd=intervals[index][1];

            if(curStart<=lastEnd){
                // overlap
                mergedIntervals.back()[1]=max(lastEnd, curEnd);
            }else{
                // no overlap
                mergedIntervals.push_back(intervals[index]);
            }

            index++;
        }

        return mergedIntervals;
    }
};