// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/trapping-rain-water/

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }
    int water_trapped{0};
    int left_max{0}, right_max{0};
    size_t left{0}, right{height.size() - 1};
    while (left < right) {
      left_max = max(left_max, height[left]);
      right_max = max(right_max, height[right]);
      if (left_max <= right_max) {
        water_trapped += left_max - height[left];
        left++;
      } else {
        water_trapped += right_max - height[right];
        right--;
      }
    }
    return water_trapped;
  }
};
// @lc code=end
