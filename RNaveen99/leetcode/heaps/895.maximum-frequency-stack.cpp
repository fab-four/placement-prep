/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-frequency-stack/
 */

// design
// First the max heap based ordering is decided by frequency and then by index, all this is implicitly done by
// C++
// O(log(n)) for both push and pop
class FreqStack {
    unordered_map<int, int> frequency;
    priority_queue<pair<int, pair<int, int>>> pq;
    int index;

  public:
    FreqStack() { index = 0; }

    void push(int val) {
        frequency[val]++;
        pq.emplace(frequency[val], make_pair(index, val));
        index++;
    }

    int pop() {
        auto top = pq.top();
        pq.pop();
        int val = top.second.second;
        frequency[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// O(1) for both push and pop
class FreqStack {
    unordered_map<int, int> frequency;
    unordered_map<int, stack<int>> frequencyBucket;
    int maxFrequency;

  public:
    FreqStack() { maxFrequency = 0; }

    void push(int val) {
        frequency[val]++;
        maxFrequency = max(maxFrequency, frequency[val]);
        frequencyBucket[frequency[val]].emplace(val);
    }

    int pop() {
        int top = frequencyBucket[maxFrequency].top();
        frequencyBucket[maxFrequency].pop();
        if (frequencyBucket[maxFrequency].empty()) {
            maxFrequency--;
        }
        frequency[top]--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */