// https://leetcode.com/problems/sliding-window-maximum/description/

/*
We have windows of size k
now 1 3 -1 -3 -5

when we push 1 and then 3 do we need 1 since all new windows will have both 1 and 3 so 3 will overpower 1
also since we want to invalidate an element we also store the index

so we use a deque with descending order 
We first remove elements depending on the index as they are invalid for that window
Then we remove elements that are smaller 

Why descending for example 1 3 -1 -3 -5
after 3 we need -1 since there can be new windows to the right where 3 won't be present but -1 will be
but if we have 1 3 5 then we don't need 3 since if 3 in window or not both cases ans will be 5

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int> > dq; // value, index
        vector<int> ans;

        int n=nums.size();

        for(int i=0;i<min(n,k);i++){
            while(!dq.empty() && nums[i]>=dq.back().first){
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }
        
        ans.push_back(dq.front().first);

        if(n<=k){
            return ans;
        }

        for(int i=k;i<n;i++){
            // remove element i-k from deque front
            while(!dq.empty() && dq.front().second<=i-k){
                dq.pop_front();
            }

            // Add element maintaining deque order
            while(!dq.empty() && nums[i]>=dq.back().first){
                dq.pop_back();
            }

            dq.push_back({nums[i], i});

            ans.push_back(dq.front().first);
        }

        return ans;
        
    }
};