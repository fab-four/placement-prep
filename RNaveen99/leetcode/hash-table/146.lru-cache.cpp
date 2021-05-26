/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/lru-cache/
 */

class LRUCache {
    int capacity;
    list<pair<int, int>> dataList;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

  public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        auto itr = cache.find(key);
        if (itr == cache.end()) {
            return -1;
        }
        int value = itr->second->second;
        dataList.erase(itr->second);
        dataList.push_front({key, value});
        cache[key] = dataList.begin();
        return value;
    }

    void put(int key, int value) {
        auto itr = cache.find(key);
        if (itr == cache.end()) {
            if (cache.size() == capacity) {
                int LRUkey = dataList.back().first;
                cache.erase(LRUkey);
                dataList.pop_back();
            }
            dataList.push_front({key, value});
            cache[key] = dataList.begin();
        } else {
            dataList.erase(itr->second);
            dataList.push_front({key, value});
            cache[key] = dataList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */