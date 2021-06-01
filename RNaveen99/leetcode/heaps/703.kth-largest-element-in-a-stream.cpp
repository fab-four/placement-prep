/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */

class KthLargest {
    priority_queue<int, vector<int>, greater<>> minHeap;
    int kLargest = 0;

  public:
    KthLargest(int k, vector<int> &nums) {
        kLargest = k;
        for (int ele : nums) {
            add(ele);
        }
    }

    int add(int val) {
        if (minHeap.size() >= kLargest) {
            minHeap.emplace(val);
            minHeap.pop();
        } else {
            minHeap.emplace(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */