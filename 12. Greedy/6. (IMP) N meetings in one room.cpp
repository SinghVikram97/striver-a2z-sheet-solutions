// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// IMP due to sorting

// Sort by ending times and execute one by one
class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        
        vector<pair<int,int> > meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({start[i], end[i]});
        }
        
        sort(meetings.begin(),meetings.end(), [](const auto &x, const auto &y){
            return x.second<y.second;
        });
        
        int index=0;
        
        int ans=0;
        int endingTime=-1;
        
        while(index<n){
            if(meetings[index].first>endingTime){
                ans++;
                endingTime=meetings[index].second;
            }else{
                index++;
            }
        }
        return ans;
    }
};