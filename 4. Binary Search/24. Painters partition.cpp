// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
#include<bits/stdc++.h>
bool isPossible(vector<int> &boards, int maxTime, int k) {

  // maxTime here means maximum time any painter can take
  // we can increase the number of painters by decreasing the time
  // but we can't decrease the number of painters by increasing time since
  // maxTime is fixed.

  // so incase painters <=k then possible
  int painters = 1;
  int timeTaken = 0;

  for (int i = 0; i < boards.size(); i++){
      if(boards[i]>maxTime){
          return false;
      }
      if(timeTaken+boards[i]<=maxTime){
          timeTaken+=boards[i];
      }else{
          // assign to next painter
          painters++;
          timeTaken=boards[i];
          if(painters>k){
              return false;
          }
      }
  }
  return painters<=k;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    // we want to find time taken to paint all the paintings 
    // and minimize it

    // time taken will be max(time taken by every painter) -> minimize this
    
    int mini=INT_MAX;
    int sum=0;

    int n=boards.size();

    for(int i=0;i<n;i++){
        mini=min(mini, boards[i]);
        sum+=boards[i];
    }

    int start=mini;
    int end=sum;

    int ans=0;
    while(start<=end){
        int mid=(start+end)/2;

        if(isPossible(boards, mid, k)){
            ans=mid;
            // minimize this max time taken
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}