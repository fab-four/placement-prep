// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(k)
  KthLargest(int k, vector<int> &nums) {
    n = k;
    for (auto num : nums) {
      pq.push(num);
      if (pq.size() > n) {
        pq.pop();
      }
    }
  }
  // Time Complexity: O(log(n))
  int add(int val) {
    pq.push(val);
    if (pq.size() > n) {
      pq.pop();
    }
    return pq.top();
  }

private:
  int n;
  priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
