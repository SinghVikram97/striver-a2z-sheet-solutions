// https://www.interviewbit.com/problems/maximum-sum-combinations/

// sort both arrays in descending order
// Take a max heap
// Push (0,0) into max heap
// Take out top of max heap and push (i,j+1) and (i+1,j) till we get C elements

// IMP: we need to check if pair (i,j+1) and (i+1,j) not already present in the heap
// For example both (0,1) and (1,0) will push (1,1)

// We use set since unordered_set doesn't support pair<int,int>
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    // element, how that element was formed ie. index in A and index in B , sum(A[i]+B[j])
    priority_queue<pair<int,pair<int,int> >> pq;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    pq.push({A[0]+B[0], {0,0}});
    
    vector<int> ans;
    
    set<pair<int,int> > ms;
    ms.insert({0,0});
    
    while(!pq.empty()){
        pair<int, pair<int,int> > topEle=pq.top();
        pq.pop();
        
        ans.push_back(topEle.first);
        
        if(ans.size()==C){
            return ans;
        }    
        
        int i=topEle.second.first;
        int j=topEle.second.second;
        
        if(ms.find({i+1,j})==ms.end()){
            pq.push({A[i+1]+B[j], {i+1,j}});
            ms.insert({i+1,j});
        }
        
        if(ms.find({i,j+1})==ms.end()){
            pq.push({A[i]+B[j+1],{i,j+1}});
            ms.insert({i,j+1});
        }
    }
    
    return ans;
}
