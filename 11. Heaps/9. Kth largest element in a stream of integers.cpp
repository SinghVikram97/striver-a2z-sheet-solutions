// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// Keep min heap of k largest elements

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> > pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<K){
            pq.push(val);
        }else{
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */