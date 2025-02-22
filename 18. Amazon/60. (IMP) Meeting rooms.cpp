// https://leetcode.com/problems/meeting-rooms/

// Same concept of merge intervals - ie sort by start times
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // sort by start times
        vector<pair<int,int> > v;

        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0], intervals[i][1]});
        }

        sort(v.begin(), v.end());

        // check if overlap
        int n=v.size();

        if(n==1 || n==0){
            return true;
        }

        pair<int,int> prev=v[0];

        for(int i=1;i<n;i++){
            int a=prev.first;
            int b=prev.second;
            int c=v[i].first;
            int d=v[i].second;

            // guaranteed that a<=c
            // so overlap if c<=b
            if(c<b){
                return false;
            }

            prev=v[i];
        }

        return true;



    }
};

//https://leetcode.com/problems/meeting-rooms-ii
// When start meeting increase count, when end decrease count
// Sort array which has both start and end

// See same problem before -> Greedy/9th Minimum platforms
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,char> > startEnd;

        for(int i=0;i<intervals.size();i++){
            startEnd.push_back({intervals[i][0], 'S'});
            startEnd.push_back({intervals[i][1], 'E'});
        }

        sort(startEnd.begin(), startEnd.end());

        int count=0;
        int ans=0;
        for(int i=0;i<startEnd.size();i++){
            if(startEnd[i].second=='S'){
                count++;
            }else{
                count--;
            }
            ans=max(ans,count);
        }

        return ans;
    }
};