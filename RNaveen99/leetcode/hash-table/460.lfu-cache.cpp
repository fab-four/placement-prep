/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/lfu-cache/
 */

// design
class LFUCache {
    int capacity;
    int size;
    int minFrequency;
    // <key , <value, frequency>>
    unordered_map<int, pair<int, int>> frequency;
    unordered_map<int, list<int>> frequencyBucket;
    unordered_map<int, list<int>::iterator> keyIterator;

  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        if (frequency.count(key) == 0) {
            return -1;
        }
        frequencyBucket[frequency[key].second].erase(keyIterator[key]);
        frequency[key].second++;
        frequencyBucket[frequency[key].second].emplace_back(key);
        keyIterator[key] = --frequencyBucket[frequency[key].second].end();

        if (frequencyBucket[minFrequency].size() == 0) {
            minFrequency++;
        }
        return frequency[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0)
            return;
        int storedValue = get(key);
        if (storedValue != -1) {
            frequency[key].first = value;
            return;
        }
        if (size >= capacity) {
            frequency.erase(frequencyBucket[minFrequency].front());
            keyIterator.erase(frequencyBucket[minFrequency].front());
            frequencyBucket[minFrequency].pop_front();
            size--;
        }
        frequency[key] = {value, 1};
        frequencyBucket[1].emplace_back(key);
        keyIterator[key] = --frequencyBucket[1].end();
        minFrequency = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */