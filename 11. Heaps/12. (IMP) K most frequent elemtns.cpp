// https://leetcode.com/problems/top-k-frequent-elements/description/

// TC: O(n*logk)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        // k most frequent elements
        // ie. most freq, most freq-1, .... 
        // 10, 8 , 7 times 
        // WE can find kth largest element in freq array
        // So from that freq to highest frequency elements we return
        
        // kth largest element -> using min heap
        priority_queue<int, vector<int>, greater<int> > pq;

        // Push first k elements into queue
        for(auto it:mp){
            if(pq.size()<k){
                pq.push(it.second);
            }else{
                // pq.top() is the smallest element
                if(it.second>pq.top()){
                    pq.pop();
                    pq.push(it.second);
                }
            }
        }

        int kthLargestFreq=pq.top();

        vector<int> ans;
        for(auto it:mp){
            if(it.second>=kthLargestFreq){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

// Using quickselect
/*
Same as kth largest element in array here we find kth largest frequency using quickselect
*/
class Solution {
public:
        int quickSort(vector<pair<int,int > > &nums, int start, int end, int k){
        int n=end-start+1;

        if(start==end){
            return nums[start].first;
        }
        
        // select random pivot
        // b/w start and end
        // rand()%(end-start+1) -> [0, end-start]
        // + start -> [start, end]
        int pivotIndex = (rand()%(end-start+1))+start;
        int pivotFreq = nums[pivotIndex].first;

        // swap pivot with last index
        swap(nums[pivotIndex], nums[end]);

        // collect elements with freq > pivot to left (sort by freq in descending order)
        int wall=start-1;
        int i=start;
        
        while(i<end){
            if(nums[i].first > pivotFreq){
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
            return pivotFreq;
        }else if(k<rankPivot){
            // kth largest in left subarray
            return quickSort(nums, start, wall-1, k);
        }else{
            // kth largest in right subarray
            // adjust rank
            return quickSort(nums, wall+1, end, k-rankPivot);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int> > freqArr;

        for(auto it:mp){
            freqArr.push_back({it.second, it.first}); // freq, element
        }

        int kthLargestFreq = quickSort(freqArr, 0, freqArr.size()-1, k);

        vector<int> result;
        for (int i = 0; i < freqArr.size(); i++) {
            if (freqArr[i].first >= kthLargestFreq) {
                result.push_back(freqArr[i].second);
            }
        }

        return result;
    }
};


// Using bucket sort
// We have done this question sort characters by their frequency
// 5. Strings/8. (IMP) Sort characters by frequency.cpp

// We can sort numbers by their frequency in O(N) using bucket sort and then return from kth element

/*
ele->  4 5 2 1 3
freq-> 1 4 3 3 2

since we need to sort frequencies keep bucket of frequencies from 0 to maxFreq which can be size of array

element ->      0  4 3 (2,1)  5  0           0 0 
bucket index -> 0 1 2    3    4  5 ........ 12 13

add all non-zero elements into array we have a elements sorted by frequency

*/

// If non-negative numbers we can use string instead of integer for buckets for multiple element in same bucket
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
    

        // if 2,3 in same bucket we store string "23"
        vector<string> buckets(n+1,"");

        for(auto it:mp){
            buckets[it.second]+=to_string(it.first);
        }
        
        vector<int> sortedFreq;
        for(int i=0;i<buckets.size();i++){
            if(buckets[i]!=""){
                // split each character into a number
                for(int j=0;j<buckets[i].length();j++){
                    sortedFreq.push_back(buckets[i][j]-'0');
                }
            }
        }
        
        int pivotPosition=sortedFreq.size()-k;

        vector<int> ans;
        for(int i=pivotPosition;i<sortedFreq.size();i++){
            ans.push_back(sortedFreq[i]);
        }
        return ans;
    }
};


// For negative integers
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
    

        vector<vector<int> > buckets(n+1);

        for(auto it:mp){
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> sortedFreq;
        for(int i=0;i<buckets.size();i++){
            for(int j=0;j<buckets[i].size();j++){
                sortedFreq.push_back(buckets[i][j]);
            }
        }
        
        int pivotPosition=sortedFreq.size()-k;

        vector<int> ans;
        for(int i=pivotPosition;i<sortedFreq.size();i++){
            ans.push_back(sortedFreq[i]);
        }
        return ans;
    }
};