// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// TLE - Recursion
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int help(vector<pair<int,int> > meetings, int index, int prevIndex){
        int n=meetings.size();
        
        if(index == n){
            return 0;
        }
        
        // can take or don't take depends on prevIndex as well
        int op1=INT_MIN+5;
        int op2=INT_MIN+5;
        if(prevIndex==-1){
            // take or don't take
            op1=1+help(meetings, index+1, index);
            // don't take
            op2=help(meetings,index+1,prevIndex);
            
            return max(op1,op2);
        }else{
            
            // check prevIndex
            int start=meetings[index].first;
            int end=meetings[index].second;
            
            int prevStart=meetings[prevIndex].first;
            int prevEnd=meetings[prevIndex].second;
            
            if(start>prevEnd){
                // can take
                op1=1+help(meetings, index+1, index);
            }
            
            // don't take
            op2=help(meetings,index+1,prevIndex);
            return max(op1,op2);
        }
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > meetings;
        
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        return help(meetings, 0 , -1);
    }
};

// DP
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int help(vector<pair<int,int> > meetings, int index, int prevIndex, vector<vector<int> > &dp){
        int n=meetings.size();
        
        if(index > n){
            return 0;
        }
        
        if(dp[index][prevIndex]!=-1){
            return dp[index][prevIndex];
        }
        
        // can take or don't take depends on prevIndex as well
        int op1=-1;
        int op2=-1;
        if(prevIndex==0){
            // take or don't take
            op1=1+help(meetings, index+1, index,dp);
            // don't take
            op2=help(meetings,index+1,prevIndex,dp);
            
            return dp[index][prevIndex]=max(op1,op2);
        }else{
            
            // check prevIndex
            int start=meetings[index-1].first;
            int end=meetings[index-1].second;
            
            int prevStart=meetings[prevIndex-1].first;
            int prevEnd=meetings[prevIndex-1].second;
            
            if(start>prevEnd){
                // can take
                op1=1+help(meetings, index+1, index,dp);
            }
            
            // don't take
            op2=help(meetings,index+1,prevIndex,dp);
            return dp[index][prevIndex]=max(op1,op2);
        }
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > meetings;
        
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        vector<vector<int> > dp(n+10,vector<int>(n+10,-1)); 
        
        // treat as 1 based
        return help(meetings, 1 , 0 ,dp);
    }
};


// Sort by end times - greedy 
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > meetings;
        
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end(), [](const auto &x, const auto &y){
            return x.second<y.second;
        });
    
        
        // start from 1st
        int prevEnd=meetings[0].second;
        
        int ans=1;
        
        int i=1;
        
        while(i<n){
        
            
            int start=meetings[i].first;
            int end=meetings[i].second;
            
            //cout<<end<<" "<<prevEnd;
            
            if(start>prevEnd){
                prevEnd=end;
                ans++;
            }
            
            i++;
            
        }
        
        return ans;
        
    }
};