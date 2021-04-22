// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  int rob(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }
    return max(robHouses(nums, 0, nums.size() - 1),
               robHouses(nums, 1, nums.size()));
  }
  int robHouses(const vector<int> &nums, int l, int r) {
    int first = nums[l];
    int second = max(nums[l], nums[l + 1]);
    for (int i = l + 2; i < r; i++) {
      int temp = second;
      second = max(second, first + nums[i]);
      first = temp;
    }
    return second;
  };
};
