// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq(begin(nums), end(nums));
    int result = 0;
    while (!pq.empty() && k--) {
      result = pq.top();
      pq.pop();
    }
    return result;
  }
};
// @lc code=end
