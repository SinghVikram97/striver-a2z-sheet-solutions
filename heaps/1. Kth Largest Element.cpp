// https://leetcode.com/problems/kth-largest-element-in-an-array/
// min heap of k large elements
// at the top will be least large element ie. kth largest element

// if an element > min heap.top then it means it should be on heap 
// but first build a pq of size k ie. 
// insert 1st k elements into the heap and then proceed checking

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        return pq.top();
    }
};