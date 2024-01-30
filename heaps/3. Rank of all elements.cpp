// https://www.codingninjas.com/studio/problems/replace-each-element-of-array-with-its-corresponding-rank_975384

// O(n*logn)
vector<int> replaceWithRank(vector<int> &arr, int n) {
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }

    sort(v.begin(),v.end());

    int rank=1;
    arr[v[0].second]=rank;

    for(int i=1;i<n;i++){
       if(v[i].first!=v[i-1].first){
           rank++;
       }
       arr[v[i].second]=rank;
    }
    return arr;
}

// By priority queue
vector<int> replaceWithRank(vector<int> &arr, int n) {
   priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

   for(int i=0;i<n;i++){
       pq.push(make_pair(arr[i],i));
   }
   
   int rank=1;
   int prev=INT_MIN-5;
   while(!pq.empty()){
       pair<int,int> topEle = pq.top();
       pq.pop();

       if(prev==INT_MIN-5){
           arr[topEle.second]=rank;
           prev=topEle.first;
       }else if(topEle.first!=prev){
           rank++;
           arr[topEle.second]=rank;
           prev=topEle.first;
       }else{
           arr[topEle.second]=rank;
           prev=topEle.first;
       }
   }

   return arr;
}