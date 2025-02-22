// https://leetcode.com/problems/lru-cache/description/
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