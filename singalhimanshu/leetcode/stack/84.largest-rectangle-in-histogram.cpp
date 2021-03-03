// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int largest_area{0};
    stack<int> s;
    int cur_area{0};
    auto heights_size{heights.size()};
    for (size_t i = 0; i <= heights_size; i++) {
      while ((i == heights_size && !s.empty()) ||
             (!s.empty() && heights[s.top()] >= heights[i])) {
        int cur = heights[s.top()];
        s.pop();
        int small_idx = s.empty() ? -1 : s.top();
        cur_area = (i - small_idx - 1) * cur;
        largest_area = max(largest_area, cur_area);
      }
      s.push(i);
    }
    return largest_area;
  }
};
// @lc code=end
