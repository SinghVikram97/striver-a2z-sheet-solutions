// https://leetcode.com/problems/find-median-from-data-stream/description/

// 2 Priority queues - min_heap, max_heap

// min heap of higher elements 
// max heap of lower elements

// max diff in size should be 1
// median - if size equal - average of top elements
// else if size unequal - top of larger sized heap

class MedianFinder {
public:
    priority_queue<int> lowers; // max heap of lower elements [0,n];
    priority_queue<int, vector<int>, greater<int>> highers; // min heap of higher elements ie [n/2,n-1]
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if num less than max ie. top of lower elements then add to lowers
        if(lowers.empty() || num<lowers.top()){
            lowers.push(num);
        }else{
            highers.push(num);
        }

        // rebalance
        int lowerSize=lowers.empty() ? 0 : lowers.size();
        int higherSize=highers.empty() ? 0 : highers.size();
        if(lowerSize-higherSize>1){
            int element = lowers.top();
            lowers.pop();
            highers.push(element);
        }
        else if(higherSize-lowerSize>1){
            int element = highers.top();
            highers.pop();
            lowers.push(element);
        }
    }
    
    double findMedian() {
        int lowerSize=lowers.empty() ? 0 : lowers.size();
        int higherSize=highers.empty() ? 0 : highers.size();

        if(lowerSize==0 && higherSize==0){
            return NULL;
        }
        else if(lowerSize==higherSize){
            return ((double)lowers.top() + highers.top())/2.0;
        }
        else if(lowerSize>higherSize){
            return lowers.top();
        }else{
            return highers.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */