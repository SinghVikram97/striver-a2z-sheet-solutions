// https://leetcode.com/problems/insert-interval/description/

// Based on previous question
/*
New interval can be at front, middle or end
so 3 conditions
*/
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


        // Check if at front
        if(intervals[0][0]<newInterval[0]){
            mergedIntervals.push_back(intervals[0]);
            i++;
        }else{
            mergedIntervals.push_back(newInterval);
            isHandled=true;
        }

        // Middle
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
        

        // End
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