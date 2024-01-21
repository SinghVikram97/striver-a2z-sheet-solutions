// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Brute force

// In each iteration check if train can become part of current platform
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        if(n==0 || n==1){
            return n;
        }
    	vector<pair<int,int> > trains;
    	
    	for(int i=0;i<n;i++){
    	    trains.push_back(make_pair(arr[i],dep[i]));
    	}
    	
    	sort(trains.begin(),trains.end());
    	
    	vector<int> platforms(n,-1);
    	
    	bool allComplete=false;
    	int platformNum=0;
    	
    	while(1){
    	    
    	    int prevEnd=-1;
    	    bool allComplete=true;
    	    
    	    for(int i=0;i<n;i++){
    	        if(platforms[i]==-1){
    	            allComplete=false;
    	            if(prevEnd==-1){
    	                // new platform
    	                platformNum++;
    	                prevEnd=trains[i].second;
    	                platforms[i]=platformNum;
    	            }else{
    	                // check if part of previous platform
    	                if(trains[i].first>prevEnd){
    	                    platforms[i]=platformNum;
    	                    prevEnd=trains[i].second;
    	                }
    	            }
    	        }
    	        else{
    	            continue;
    	        }
    	    }
    	    
    	    if(allComplete){
    	        return platformNum;
    	    }
    	    
    	    prevEnd=-1;
    	}
    
        
    	return platformNum;
    }
};


// Optimised greedy
// merge arrivals and departures and sort them
// for each arrival increment the platform for each departure decrement the platform
// ans is max number of platforms used at any time

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int> > arrivalDeparture;
    	
    	for(int i=0;i<n;i++){
    	    arrivalDeparture.push_back(make_pair(arr[i],0)); // 0-A
    	    arrivalDeparture.push_back(make_pair(dep[i],1)); // 1-D
    	}
    	
        // sort
        sort(arrivalDeparture.begin(),arrivalDeparture.end());
        
    	int platforms=0;
    	int ans=-1;
    	for(int i=0;i<arrivalDeparture.size();i++){
            if(arrivalDeparture[i].second==0){
                platforms++;
            }else{
                platforms--;
            }
            ans=max(ans,platforms);
        }
    	return ans;
    	
    }
};