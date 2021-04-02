// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/sliding-window-maximum/

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    auto n = nums.size();
    if (n < 2 || k == 1) {
      return nums;
    }
    // {val, idx}
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
      pq.push({nums[i], i});
    }
    vector<int> result;
    result.reserve(n);
    result.emplace_back(pq.top().first);
    for (int i = k; i < n; i++) {
      while (!pq.empty() && pq.top().second < i - k + 1) {
        pq.pop();
      }
      pq.push({nums[i], i});
      result.emplace_back(pq.top().first);
    }
    return result;
  }
};
// @lc code=end
