// https://leetcode.com/problems/lfu-cache/description/

/*
We keep a map of key, (value, freq, position in the list)
And then we have another map for
freq -> list<int> [ all elements with given freq]

we also maintain a minimum freq
*/

class LFUCache {
public:
    int _minFreq;
    int _capacity;
    unordered_map<int, pair<int,int> > _cache; // key -> (value, freq)
    unordered_map<int, list<int>::iterator> _listmap; // key -> position in the list of freqMap to erase in O(1)
    unordered_map<int, list<int> > _freqmap; // freq -> list of keys which are sorted ie. at last is lru

    LFUCache(int capacity) {
        _minFreq=0;
        _capacity=capacity;
    }
    
    int get(int key) {
        if(_cache.find(key)==_cache.end()){
            return -1;
        }

        use(key);

        return _cache[key].first;
    }
    
    void put(int key, int value) {
        if(_cache.find(key)!=_cache.end()){
            use(key);
            _cache[key].first=value;
            return;
        }else{
            if(_cache.size()==_capacity){
                // remove 
                int lruKey = _freqmap[_minFreq].back();

                _cache.erase(lruKey);
                _listmap.erase(lruKey);

                _freqmap[_minFreq].pop_back();

                // _minFreq will be updated to 1 since we are inserting a new key
            }

            // Now insert
            _cache[key]={value,1};
            _freqmap[1].push_front(key);
            _listmap[key]=_freqmap[1].begin();
            _minFreq=1;
            return;
        }
    }

    void use(int key){
        _cache[key].second=_cache[key].second+1;

        int newFreq=_cache[key].second;
        int originalFreq=newFreq-1;

        auto it = _listmap[key]; // position in freqmap[originalFreq]

        _freqmap[originalFreq].erase(it);

        _freqmap[newFreq].push_front(key);
        _listmap[key]=_freqmap[newFreq].begin();

        // update minFreq incase
        if(originalFreq==_minFreq && _freqmap[originalFreq].size()==0){
            _minFreq=newFreq;
        }

        return;
    }
};