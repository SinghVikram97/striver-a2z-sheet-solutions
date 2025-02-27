// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Brute force - O(nlogn)
// Sort the array and then element at index k-1

// Min heap of k largest elements
// Top of the heap would have kth largest element

// min heap of k large elements
// at the top will be least large element ie. kth largest element

// if an element > min heap.top then it means it should be on heap 
// but first build a pq of size k ie. 
// insert 1st k elements into the heap and then proceed checking

// TC: O(nlogk)
// SC: O(k)
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



// Quickselect
// TC: O(N^2) worst case Average case will be O(N)
class Solution {
public:
    int quickSort(vector<int> &nums, int start, int end, int k){
        int n=end-start+1;

        if(start==end){
            return nums[start];
        }
        
        // select random pivot
        // b/w start and end
        // rand()%(end-start+1) -> [0, end-start]
        // + start -> [start, end]
        int pivotIndex = (rand()%(end-start+1))+start;
        int pivotNumber = nums[pivotIndex];

        // swap pivot with last index
        swap(nums[pivotIndex], nums[end]);

        // collect numbers > pivot to left ( SORT IN DESCENDING ORDER)
        int wall=start-1;
        int i=start;
        
        while(i<end){
            if(nums[i]>pivotNumber){
                wall++;
                swap(nums[i], nums[wall]);
            }
            i++;
        }

        // now wall at last element > pivot
        // put pivot in place which is at the end
        wall++;
        swap(nums[wall], nums[end]);

        // IMP to consider from start
        int rankPivot = wall-start+1; 

        if(rankPivot==k){
            return pivotNumber;
        }else if(k<rankPivot){
            // kth largest in left subarray
            return quickSort(nums, start, wall-1, k);
        }else{
            // kth largest in right subarray
            // adjust rank
            return quickSort(nums, wall+1, end, k-rankPivot);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size()-1, k);
    }
};