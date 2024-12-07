// https://leetcode.com/problems/non-overlapping-intervals/

/*
(a,b)(c,d)
overlap cause by c<b ie. end time of previous

sort by start time

a b c

now if a and b overlap which one to remove?

we just remove b everytime there can be a case where a and c overlap
[1,5] [3,4] [4,7]
here remove a 

if we remove b then there is still overlap we would need to remove 2 intervals
but we remove a no overlap we only need to remove 1 interval

[1,2][1,3][2,3]

here if we remove b we get minimum
if we remove a we would still have overlap

We remove one with larger end?? YES
greedily remove intervals with large end times

Instead sort by end times
(a,b) (c,d)

given b<=d 
overlap incase c<b (not c=b since that is not considered overlap)
and incase overlap we remove 2nd one cause it has larger end
*/

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