// https://www.naukri.com/code360/problems/longest-successive-elements_6811740

// Brute force - O(NlogN)
// 
int longestSuccessiveElements(vector<int>&a) {
   sort(a.begin(), a.end());

   int n=a.size();

   if(n<=1){
       return n;
   }

   int cs=1;
   int ms=1;

   for(int i=1;i<n;i++){
       if(a[i]-a[i-1]==1){
           cs++;
           ms=max(ms,cs);
       }else if(a[i]==a[i-1]){ // skip equals important
           continue;
        }else{
           cs=1;
       }
   }
   return ms;
}


/*
If a number is a start of sequence then num-1 won't exist
So we find numbers for which num-1 doesn't exist and find longest sequence for them using set
Time: O(N)
*/
int longestSuccessiveElements(vector<int>&a) {
   int maxi=-1;
   int n=a.size();

   unordered_set<int> ms;
   for(int i=0;i<n;i++){
       ms.insert(a[i]);
   }

   // traverse the set
   for(auto it=ms.begin();it!=ms.end();it++){
       int num=(*it);
       if(ms.find(num-1)==ms.end()){
           // start sequence from this number
           int len=0;
           while(ms.find(num)!=ms.end()){
               len++;
               num=num+1;
           }
           maxi=max(maxi, len);
       }
   }

   return maxi;
}