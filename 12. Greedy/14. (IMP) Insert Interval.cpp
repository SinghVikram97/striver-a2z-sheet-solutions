// https://leetcode.com/problems/insert-interval/

/*
Since sorted by start time so 
start time of right interval > start time of left

if start time of right interval < end time of left interval

intervals will be merged to (leftStartTime, max(leftEndTime, rightEndTime))
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int > > mergedIntervals;

        mergedIntervals.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int nextStart=intervals[i][0];
            int nextEnd=intervals[i][1];

            int curStart=mergedIntervals.back()[0];
            int curEnd=mergedIntervals.back()[1];

            if(nextStart<=curEnd){
                mergedIntervals.back()[1]=max(curEnd, nextEnd);
            }else{
                mergedIntervals.push_back(intervals[i]);
            }

        }

        return mergedIntervals;
    }
};


// Without sorting again
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(intervals.size()==0){
            return {newInterval};
        }
        
        vector<vector<int > > mergedIntervals;

        bool isHandled=false;
        int i=0;

        if(intervals[0][0]<newInterval[0]){
            mergedIntervals.push_back(intervals[0]);
            i++;
        }else{
            mergedIntervals.push_back(newInterval);
            isHandled=true;
        }

        while(i<n){
            vector<int> nextInterval;

            if(!isHandled && newInterval[0]<intervals[i][0]){
                nextInterval=newInterval;
                isHandled=true;
            }else{
                nextInterval=intervals[i];
                i++;
            }

            int nextStart=nextInterval[0];
            int nextEnd=nextInterval[1];

            int curStart=mergedIntervals.back()[0];
            int curEnd=mergedIntervals.back()[1];

            if(nextStart<=curEnd){
                mergedIntervals.back()[1]=max(curEnd, nextEnd);
            }else{
                mergedIntervals.push_back(nextInterval);
            }
        }

        if(!isHandled){
            vector<int> nextInterval=newInterval;
            isHandled=true;

            int nextStart=nextInterval[0];
            int nextEnd=nextInterval[1];

            int curStart=mergedIntervals.back()[0];
            int curEnd=mergedIntervals.back()[1];

            if(nextStart<=curEnd){
                mergedIntervals.back()[1]=max(curEnd, nextEnd);
            }else{
                mergedIntervals.push_back(nextInterval);
            }
        }
    
        return mergedIntervals;
    }
};