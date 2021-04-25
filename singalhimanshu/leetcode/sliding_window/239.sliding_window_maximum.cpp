// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    deque<int> cur_max;
    int i = 0, j = 0;
    while (j < nums.size()) {
      while (!cur_max.empty() && cur_max.back() < nums[j]) {
        cur_max.pop_back();
      }
      cur_max.push_back(nums[j]);
      if (j - i + 1 == k) {
        res.emplace_back(cur_max.front());
        if (nums[i] == cur_max.front()) {
          cur_max.pop_front();
        }
        i++;
      }
      j++;
    }
    return res;
  }
};
