// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int longestSubarray(vector<int> &nums, int limit) {
    deque<int> max_dq;
    deque<int> min_dq;
    int ans = 0;
    int i = 0, j = 0;
    while (j < nums.size()) {
      while (!max_dq.empty() && max_dq.back() < nums[j]) {
        max_dq.pop_back();
      }
      max_dq.push_back(nums[j]);
      while (!min_dq.empty() && min_dq.back() > nums[j]) {
        min_dq.pop_back();
      }
      min_dq.push_back(nums[j]);
      if ((max_dq.front() - min_dq.front()) <= limit) {
        ans = max(ans, j - i + 1);
      }
      while ((max_dq.front() - min_dq.front()) > limit) {
        if (nums[i] == max_dq.front()) {
          max_dq.pop_front();
        }
        if (nums[i] == min_dq.front()) {
          min_dq.pop_front();
        }
        i++;
      }
      j++;
    }
    return ans;
  }
};
