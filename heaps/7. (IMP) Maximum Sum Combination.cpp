// https://www.interviewbit.com/problems/maximum-sum-combinations/
/*
Take heap of sum, index(i,j)
sort array 
i=n-1,j=n-1
push i,j in heap

take out top element
push (i-1,j) and (i,j-1) into pq

until we get C elements

IMP: we need to check pair (i-1,j) and (i,j-1) not already present in heap
// need to check for duplicates

*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int,pair<int,int> > > pq;
    set<pair<int,int>> ms;	
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int n = A.size();
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    ms.insert({n-1,n-1});
    
    vector<int> ans;
    while(C){
        pair<int,pair<int,int> > topEle=pq.top();
        pq.pop();
        
        ans.push_back(topEle.first);
        
        int i=topEle.second.first;
        int j=topEle.second.second;
        
        if(ms.find({i-1,j})==ms.end()){
            pq.push({A[i-1]+B[j],{i-1,j}}); 
            ms.insert({i-1,j});
        }
        if(ms.find({i,j-1})==ms.end()){
            pq.push({A[i]+B[j-1],{i,j-1}});  
            ms.insert({i,j-1});
        }
        
        C--;
    }
    
    return ans;
}

