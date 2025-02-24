// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Min heap of k largest elements
// Top of the heap would have kth largest element

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


// Using binary search
class Solution {
public:
    int upperBound(int target, vector<int> &v){
        int size=v.size();
        if(size==0){
            return -1; // returns index
        }

        int start=0;
        int end=size-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(v[mid]<=target){
                ans=mid;
                // move further right
                start=mid+1;
            }else{
                // move left
                end=mid-1;
            }
        }
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        // kth largest would lie at position
        int position=n-k;

        int start=0;
        int end=n-1;

        int ans=-1;
        // answer would be leftmost number where number of elements <= num atleast position (>=position)
        while(start<=end){
            int mid=(start+end)/2;
            int numElementsLessThanEqual=upperBound(nums[mid], nums);

            if(numElementsLessThanEqual>=position){
                ans=nums[mid];
                // move left
                end=mid-1;
            }else{
                // move right
                start=mid+1;
            }
        }

        return ans;
    }
};