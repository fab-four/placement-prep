/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-median-from-data-stream/
 */

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

  public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.emplace(num);
        minHeap.emplace(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + minHeap.top()) / 2;
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */