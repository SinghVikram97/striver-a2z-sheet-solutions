// https://www.interviewbit.com/problems/nearest-smaller-element/
vector<int> Solution::prevSmaller(vector<int> &nums) {
    int n=nums.size();
    
    vector<int> nse(n,-1);
    stack<int> ms;
    
    for(int i=0;i<n;i++){
        while(!ms.empty() && nums[i]<=ms.top()){
            ms.pop();
        }
        
        if(ms.empty()){
            nse[i]=-1;
        }else{
            nse[i]=ms.top();
        }
        
        ms.push(nums[i]);
    }
    
    return nse;
}
