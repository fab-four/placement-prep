/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<>> pq;

        for (int ele : nums) {
            pq.emplace(ele);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};