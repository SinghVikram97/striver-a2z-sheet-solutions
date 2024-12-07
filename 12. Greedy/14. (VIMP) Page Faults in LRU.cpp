// https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1


// Before this solve design LRU cache: https://leetcode.com/problems/lru-cache/description/
/*
We need to support 2 operations
- Key exists ?
- If doesn't remove least recently used key ( need to keep track of usuage )
*/

/*
Naive -> keep hashmap which solves key exist and tracks usage as well
But least recently used we need to iterate through every element

If we use priority queue then finding key exists and updating its usage becomes time consuming - O(N)

Note: LRU different from LFU, LFU depends on frequency, LRU just based on time when accessed.
IMP: Getting key -> usage and
Putting key -> also counts as usage, putting same key again with diff or same value is also use
*/

/*
We use a linked list to keep track of usage
At front -> most recently used item
At back -> least recently used item

1->2->3

let's say we hit 2 

now its easy to update position of 2 in O(1)
just remove 2 and move to front

deleting from LL -> O(1)
adding an element to front of LL -> O(1)

But we need to know position of 2 

in our unordered_map we store 3 things -> key, value and position of that key in linked list
*/
class LRUCache {
private:
    // front-> MRU
    // back -> LRU
    list<int> _lru;
    unordered_map<int,pair<int,list<int>::iterator> > _cache;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity=capacity;
    }
    
    int get(int key) {
        if(_cache.find(key)==_cache.end()){
            return -1;
        }else{
            use(key);
            return _cache[key].first;
        }
    }
    
    void put(int key, int value) {
        if(_cache.find(key)!=_cache.end()){
            use(key);
            _cache[key].first=value;
            return;
        }else{
            if(_cache.size()==_capacity){
                // remove least recently used
                int lruKey = _lru.back(); // back gets value, end gets iterator
                _cache.erase(lruKey);
                _lru.pop_back();
            }

            // now insert
            _lru.push_front(key);
            _cache[key]={value, _lru.begin()};
            return;
        }
    }

    void use(int key){
        // 1->2->3
        // 2 hit
        // erase 2 
        // push 2 again in front

        // get it's position in the linked list
        auto it=_cache[key].second;

        // delete it from this position
        _lru.erase(it);

        // push it to front
        _lru.push_front(key);

        // update position in cache
        _cache[key].second = _lru.begin();
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// Back to GFG question
// Here we don't have to store the value associated with the key
class Solution{
private:
    list<int> _lru;
    unordered_map<int, list<int>::iterator> _cache;
public:
    int pageFaults(int N, int C, int pages[]){
        // each call is a use call
        int faults=0;
        
        for(int i=0;i<N;i++){
            int key=pages[i];
            
            if(_cache.find(key)!=_cache.end()){
                // use
                use(key);
            }else{
                faults++;
                
                if(_cache.size()==C){
                    // remove LRU
                    int key = _lru.back();
                    // remove from cache
                    _cache.erase(key);
                    // remove from linked list
                    _lru.pop_back();
                }
                
                // insert new
                _lru.push_front(key);
                _cache[key]=_lru.begin();
            }
        }
        return faults;
    }
    
    void use(int key){
        // get position in linked list
        auto it = _cache[key];
        
        // erase from linked list
        _lru.erase(it);
        
        // push to front
        _lru.push_front(key);
        
        // update position
        _cache[key]=_lru.begin();
    }
};