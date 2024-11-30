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
// Quickselect 
/*
Quickselect is a textbook algorithm typically used to solve the problems 
"find kth something": kth smallest, kth largest, kth most frequent, kth less frequent, etc.
*/

/*
Find frequency of every element
ele->  4 5 2 1 3
freq-> 1 4 3 3 2

select random element as pivot for example 1
arrange array such that all elements having freq < freq1 to the left
>= to the right of 1

so
ele->   4 3 1 2 5
freq->  1 2 3 3 4

Now number of elements from pivot to end = n-i
if n-i=k it means these elements are k most frequent elements since we know every element after pivot has higher freq
even tho each left and right half may not be sorted

now if n-i>k move right
if n-i<k move left
*/ 
class Solution {
public:
    int quickSelect(vector<int> &v, unordered_map<int,int> &mp, int pivotIndex, int start, int end){
        // move pivot to end
        swap(v[pivotIndex], v[end]);

        //int wall=-1; // for elements having less freq than pivot
        int wall=start-1; // general case above for start=0

        for(int i=start;i<end;i++){
            if(mp[v[i]]<mp[v[end]]){
                wall++;
                swap(v[i], v[wall]);
            }
        }

        wall++;
        swap(v[wall],v[end]); // for pivot index
        return wall;
    }
    int driver(vector<int> &uniqueElements, unordered_map<int,int> &mp, int k){
        int n=uniqueElements.size();
        
        int start=0;
        int end=n-1;

        while(start<=end){
            // select random element as pivot
            srand(time(NULL));
            int pivotIndex=(rand()%(end-start+1))+start; // [0 -> end-start] + start -> [start -> end]

            int pivotPosition = quickSelect(uniqueElements, mp, pivotIndex, start, end);

            if(n-pivotPosition==k){
                return pivotPosition;
            }else if(n-pivotPosition>k){
                // move right
                start=pivotPosition+1;
            }else{
                // move left
                end=pivotPosition-1;
            }
        }

        return -1;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> uniqueElements;
        for (auto it : mp) {
            uniqueElements.push_back(it.first);
        }

        int pivotPosition = driver(uniqueElements, mp, k);

        vector<int> ans;
        // return elements after pivotPosition
        for(int i=pivotPosition;i<uniqueElements.size();i++){
            ans.push_back(uniqueElements[i]);
        }

        return ans;
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