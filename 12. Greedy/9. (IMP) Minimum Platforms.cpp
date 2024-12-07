// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Brute force
// For each platform store the end time for the train on it
// Then for each train assign a platform such that its arrival > end time of train at that platform
// While assigning update the end time of train at that platform

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        
        vector<pair<int,int> > v; // arrival, departure
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i], dep[i]});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> platforms;
        
        
        for(int i=0;i<n;i++){
            if(platforms.size()==0){
                platforms.push_back(v[i].second);
            }else{
                int platform=-1;
                for(int j=0;j<platforms.size();j++){
                    if(v[i].first>platforms[j]){
                        platform=j;
                        // update end time at that platform
                        platforms[j]=v[i].second;
                        break;
                    }
                }
                
                if(platform==-1){
                    platforms.push_back(v[i].second);
                }
            }    
        }
        
        return platforms.size();
    }
};

// Greedy - optimised
/*
Like in real life
Keep track of each arrival and departure
When arrival happens assign a platform
When departure happens free a platform
At any time max number of platforms used will be the answer
*/
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        
        vector<pair<int,char> > arrDep;
        
        for(int i=0;i<n;i++){
            arrDep.push_back({arr[i],'A'});
        }
        
        for(int i=0;i<n;i++){
            arrDep.push_back({dep[i],'D'});
        }
        
        sort(arrDep.begin(), arrDep.end());
        
        int platforms=0;
        int ans=-1;
        
        for(int i=0;i<arrDep.size();i++){
            if(arrDep[i].second=='A'){
                platforms++;
            }else{
                platforms--;
            }
            
            ans=max(ans, platforms);
        }
        
        return ans;
    }
};