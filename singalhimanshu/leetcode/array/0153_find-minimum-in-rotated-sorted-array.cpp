// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
  int findMin(vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
      if (nums[lo] < nums[hi]) {
        return nums[lo];
      }
      int mid = (lo + hi) / 2;
      if (nums[mid] > nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return nums[lo];
  }
};
