// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-peak-element/

constexpr int mmin = numeric_limits<int>::min();

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int left = (mid == 0) ? mmin : nums[mid - 1];
      int right = (mid == nums.size() - 1) ? mmin : nums[mid + 1];
      if (nums[mid] > left && nums[mid] > right) {
        return mid;
      } else if (mid > 0 && nums[mid - 1] > nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return 0;
  }
};
