// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int maxArea(vector<int> &height) {
    int left_ptr = 0, right_ptr = height.size() - 1;
    int res = INT_MIN;
    while (left_ptr < right_ptr) {
      int cur_min = min(height[left_ptr], height[right_ptr]);
      res = max(res, (right_ptr - left_ptr) * cur_min);
      if (height[left_ptr] <= height[right_ptr]) {
        left_ptr++;
      } else {
        right_ptr--;
      }
    }
    return res;
  }
};
