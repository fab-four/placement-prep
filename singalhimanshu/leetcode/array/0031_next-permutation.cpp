// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int first_decreasing_idx = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        first_decreasing_idx = i;
        break;
      }
    }
    if (first_decreasing_idx == -1) {
      reverse(begin(nums), end(nums));
      return;
    }
    int first_greater_idx = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] > nums[first_decreasing_idx]) {
        first_greater_idx = i;
        break;
      }
    }
    swap(nums[first_decreasing_idx], nums[first_greater_idx]);
    reverse(begin(nums) + first_decreasing_idx + 1, end(nums));
  }
};
